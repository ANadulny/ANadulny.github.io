#include "SemanticCheck.hpp"
#include "../stdlib/StdLib.hpp"
#include "../../structures/ir/includes.hpp"

using SemanticCheck = tkom::modules::SemanticCheck;
using StdLib = tkom::modules::StdLib;
namespace ir = tkom::structures::ir;
namespace ast = tkom::structures::ast;

std::vector<std::shared_ptr<ir::Function>> SemanticCheck::check(const std::shared_ptr<ast::Program>& syntaxTree)
{
	this->syntaxTree = syntaxTree;
	this->tracer.resetNestingLevel();
	this->definedFunctions.clear();

	this->scanFunctionDefinitions();
	this->checkMain();

	return this->traverseTree();
}

void SemanticCheck::scanFunctionDefinitions()
{
	this->tracer.increaseNestingLevel("Checking function definitions");

	for (auto& functionNode : this->syntaxTree->functions)
	{
		if (StdLib::hasFunction(functionNode->name))
		{
			std::string errorMsg("Redefinition of Standard Lib function: " + functionNode->name + '\n');
			throw std::exception(errorMsg.c_str());
			return;
		}

		if (this->definedFunctions.count(functionNode->name) > 0)
		{
			std::string errorMsg("Duplicated definition of function: " + functionNode->name + '\n');
			throw std::exception(errorMsg.c_str());
			return;
		}
		
		this->tracer.printMessage("Checking function " + functionNode->name);

		this->definedFunctions.insert({ { functionNode->name, std::make_shared<ir::Function>() } });
		auto& fun = this->definedFunctions.at(functionNode->name);
		fun->name = functionNode->name;

		for (auto& variable : functionNode->parameters)
		{
			if (!fun->scope.addVariable(variable))
			{
				std::string errorMsg("Duplicated definition of parameter \"" + variable + "\" of function \"" + functionNode->name + '\n');
				throw std::exception(errorMsg.c_str());
			}
			fun->scope.setVariableDefined(variable);
		}
	}
	this->tracer.decreaseNestingLevel();
}

void SemanticCheck::checkMain()
{
	if (this->definedFunctions.count("main") == 0)
	{
		std::string errorMsg("No entry point. Main function is not defined");
		throw std::exception(errorMsg.c_str());
	}

	if (this->definedFunctions.at("main")->scope.variables.size() != 0)
	{
		std::string errorMsg("Main function should not have parameters");
		throw std::exception(errorMsg.c_str());
	}
}

std::vector<std::shared_ptr<ir::Function>> SemanticCheck::traverseTree()
{
	std::vector<std::shared_ptr<ir::Function>> functions;

	for (auto& function : this->syntaxTree->functions)
		functions.push_back(this->checkFunction(*function));

	return functions;
}

std::shared_ptr<ir::Function> SemanticCheck::checkFunction(ast::FunctionDef& functionDef)
{
	this->tracer.increaseNestingLevel("Checking function: " + functionDef.name);
	auto& function = this->definedFunctions.at(functionDef.name);
	function->instructions.push_back(this->checkBlock(function->scope, *(functionDef.blockNode)));
	this->tracer.decreaseNestingLevel();
	return function;
}

std::shared_ptr<ir::Block> SemanticCheck::checkBlock(ir::Scope& scope, ast::StatementBlock& blockNode)
{
	std::shared_ptr<ir::Block> block = std::make_shared<ir::Block>();
	block->scope.upperScope = &scope;
	this->tracer.increaseNestingLevel("Checking block: ");

	for (auto& instruction : blockNode.instructions)
	{
		switch (instruction->getType())
		{
			case ast::Node::Type::InitStatement:
			{
				auto node = static_cast<ast::InitStatement*>(instruction.get());
				this->checkVarDeclaration(block->scope, node->name);

				if (node->mathExpressionNode)
				{
					block->instructions.push_back(this->checkAssignment(block->scope, node->name, *(node->mathExpressionNode)));
				}
				break;
			}
			case ast::Node::Type::Assignment:
			{
				auto node = static_cast<ast::Assignment*>(instruction.get());
				block->instructions.push_back(this->checkAssignment(block->scope, *(node->variable), *(node->value)));
				break;
			}
			case ast::Node::Type::ReturnStatement:
			{
				auto node = static_cast<ast::ReturnStatement*>(instruction.get());
				block->instructions.push_back(this->checkReturnStatement(block->scope, *(node->mathExpressionNode)));
				break;
			}
			case ast::Node::Type::FunctionCall:
			{
				auto node = static_cast<ast::FunctionCall*>(instruction.get());
				block->instructions.push_back(this->checkFunctionCall(block->scope, *node));
				break;
			}
			case ast::Node::Type::IfStatement:
			{
				auto node = static_cast<ast::IfStatement*>(instruction.get());
				block->instructions.push_back(this->checkIfStatement(block->scope, *node));
				break;
			}
		case ast::Node::Type::WhileStatement:
		{
			auto node = static_cast<ast::WhileStatement*>(instruction.get());
			block->instructions.push_back(this->checkWhileStatement(block->scope, *node));
			break;
		}
		case ast::Node::Type::LoopJump:
		{
			auto node = std::make_shared<ir::instructions::LoopJump>();
			node->isBreak = (static_cast<ast::LoopJump*>(instruction.get()))->isBreak;
			block->instructions.push_back(node);
			break;
		}
		case ast::Node::Type::PrintfStatement:
		{
			auto node = static_cast<ast::PrintfStatement*>(instruction.get());
			block->instructions.push_back(this->checkPrintfStatement(block->scope, *node));
			break;
		}
			default:
			{
				std::string errorMsg("Invalid instruction node type");
				throw std::exception(errorMsg.c_str());
			}
		}
	}
	this->tracer.decreaseNestingLevel();
	return block;
}

void SemanticCheck::checkVarDeclaration(ir::Scope& scope, const std::string& name)
{
	this->tracer.increaseNestingLevel("Checking var declaration");
	if (!scope.addVariable(name))
	{
		std::string errorMsg("Redeclaration of variable: " + name);
		throw std::exception(errorMsg.c_str());
	}
	this->tracer.decreaseNestingLevel();
}

std::shared_ptr<ir::instructions::Assignment> SemanticCheck::checkAssignment(ir::Scope& scope, const std::string& variable, ast::MathExpression& mathExpression)
{
	std::shared_ptr<ir::instructions::Assignment> node = std::make_shared<ir::instructions::Assignment>();
	this->tracer.increaseNestingLevel("Checking (var) assignment");
	
	if (!scope.hasVariable(variable))
	{
		std::string errorMsg("Assignment to undefined variable" + variable + '\n');
		throw std::exception(errorMsg.c_str());
	}

	node->variable->name = variable;
	node->value = this->checkExpression(scope, mathExpression);

	scope.setVariableDefined(variable);
	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ir::instructions::Assignment> SemanticCheck::checkAssignment(ir::Scope& scope, ast::Variable& variable, ast::MathExpression& mathExpression) {
	
	std::shared_ptr<ir::instructions::Assignment> node = std::make_shared<ir::instructions::Assignment>();
	this->tracer.increaseNestingLevel("Checking assignment");

	if (!scope.hasVariable(variable.variableName))
	{
		std::string errorMsg("Assignment to undefined variable: " + variable.variableName);
		throw std::exception(errorMsg.c_str());
	}

	node->variable->name = variable.variableName;
	node->value = this->checkExpression(scope, mathExpression);

	scope.setVariableDefined(node->variable->name);

	tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ir::Expression> SemanticCheck::checkExpression(ir::Scope& scope, ast::MathExpression& mathExpression)
{
	std::shared_ptr<ir::Expression> node = std::make_shared<ir::Expression>();
	this->tracer.increaseNestingLevel("Checking math expression");

	node->operations = mathExpression.operations;

	for (auto& operand : mathExpression.operands)
	{
		if (operand->getType() == Node::Type::MathExpression)
		{
			node->operands.push_back(this->checkExpression(scope, *(static_cast<ast::MathExpression*>(operand.get()))));
		}
		else if (operand->getType() == Node::Type::Variable)
		{
			node->operands.push_back(this->checkVariable(scope, *(static_cast<ast::Variable*>(operand.get()))));
		}
		else if (operand->getType() == Node::Type::NumberLiteral) {
			node->operands.push_back(this->checkLiteral(scope, *(static_cast<ast::NumberLiteral*>(operand.get()))));
		}
		else if (operand->getType() == Node::Type::FunctionCall) {
			node->operands.push_back(this->checkFunctionCall(scope, *(static_cast<ast::FunctionCall*>(operand.get()))));
		}
		else
		{
			std::string errorMsg("Invalid expression operand");
			throw std::exception(errorMsg.c_str());
		}
	}
	
	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ir::instructions::FunctionCall> SemanticCheck::checkFunctionCall(ir::Scope& scope, ast::FunctionCall& functionCall)
{
	this->tracer.increaseNestingLevel("Checking function call");

	if (this->definedFunctions.count(functionCall.functionName) == 0 && !StdLib::hasFunction(functionCall.functionName) && !StdLib::hasObjectFunction(functionCall.functionName))
	{
			std::string errorMsg("Call to undefined function: " + functionCall.functionName);
			throw std::exception(errorMsg.c_str());
	}

	if (this->definedFunctions.count(functionCall.functionName) == 1)
	{
		auto &functionDef = this->definedFunctions.at(functionCall.functionName);
		if (functionDef->scope.variables.size() != functionCall.arguments.size())
		{
			std::string errorMsg("Wrong number of arguments in function " + functionCall.functionName + " expected: " + std::to_string(functionDef->scope.variables.size())
				+ " got: " + std::to_string(functionCall.arguments.size()));
			throw std::exception(errorMsg.c_str());
		}
	}
	else if(functionCall.objectName != "")
	{
		unsigned int requiredArgs = StdLib::getObjectFunctionParamsCount(functionCall.functionName);
		if (requiredArgs != functionCall.arguments.size())
		{
			std::string errorMsg("Wrong number of arguments in function " + functionCall.functionName + " expected: " + std::to_string(requiredArgs)
				+ " got: " + std::to_string(functionCall.arguments.size()));
			throw std::exception(errorMsg.c_str());
		}
	}
	else
	{
		unsigned int requiredArgs = StdLib::getFunctionParamsCount(functionCall.functionName);
		if (requiredArgs != functionCall.arguments.size())
		{
			std::string errorMsg("Wrong number of arguments in function " + functionCall.functionName + " expected: " + std::to_string(requiredArgs)
				+ " got: " + std::to_string(functionCall.arguments.size()));
			throw std::exception(errorMsg.c_str());
		}
	}

	std::shared_ptr<ir::instructions::FunctionCall> obj = std::make_shared<ir::instructions::FunctionCall>();
	obj->name = functionCall.functionName;

	for (auto& argument : functionCall.arguments)
		obj->arguments.push_back(this->checkExpression(scope, *argument));

	if (functionCall.objectName != "")
		obj->objectName = functionCall.objectName;

	this->tracer.decreaseNestingLevel();
	return obj;
}
std::shared_ptr<ir::Literal> SemanticCheck::checkLiteral(ir::Scope& scope, ast::NumberLiteral& numberLiteral)
{
	this->tracer.increaseNestingLevel("Checking number literal");

	std::shared_ptr<ir::Literal> literal = std::make_shared<ir::Literal>();
	literal->data.push_back(numberLiteral.value);
	literal->setDeterminant();
	this->tracer.decreaseNestingLevel();
	return literal;
}

std::shared_ptr<ir::Variable> SemanticCheck::checkVariable(ir::Scope& scope, ast::Variable& variable)
{
	std::shared_ptr<ir::Variable> obj = std::make_shared<ir::Variable>();
	this->tracer.increaseNestingLevel("Checking variable");
	
	if (!scope.hasVariable(variable.variableName))
	{
		std::string errorMsg("Usage of undefined variable: " + variable.variableName);
		throw std::exception(errorMsg.c_str());
	}

	if (!scope.isVariableDefined(variable.variableName))
	{
		std::string errorMsg("Usage of empty variable: " + variable.variableName);
		throw std::exception(errorMsg.c_str());
	}
	
	obj->name = variable.variableName;
	this->tracer.decreaseNestingLevel();
	return obj;
}

std::shared_ptr<ir::instructions::Return> SemanticCheck::checkReturnStatement(ir::Scope& scope, ast::MathExpression& mathExpression)
{
	std::shared_ptr<ir::instructions::Return> obj = std::make_shared<ir::instructions::Return>();
	tracer.increaseNestingLevel("Checking return statement");
	obj->value = this->checkExpression(scope, mathExpression);
	tracer.decreaseNestingLevel();
	return obj;
}

std::shared_ptr<ir::instructions::IfStatement> SemanticCheck::checkIfStatement(ir::Scope& scope, ast::IfStatement& stmt)
{
	std::shared_ptr<ir::instructions::IfStatement> obj = std::make_shared<ir::instructions::IfStatement>();
	tracer.increaseNestingLevel("Checking if statement");
	obj->condition = this->checkCondition(scope, *(stmt.logicExpresionNode));

	obj->trueBlock = this->checkBlock(scope, *(stmt.ifBlockNode));
	if (stmt.elseBlockNode)
	{
		obj->falseBlock = this->checkBlock(scope, *(stmt.elseBlockNode));
	}

	tracer.decreaseNestingLevel();
	return obj;
}

std::shared_ptr<ir::instructions::WhileStatement> SemanticCheck::checkWhileStatement(ir::Scope& scope, ast::WhileStatement& stmt)
{
	std::shared_ptr<ir::instructions::WhileStatement> obj = std::make_shared<ir::instructions::WhileStatement>();
	tracer.increaseNestingLevel("Checking while statement");

	obj->condition = this->checkCondition(scope, *(stmt.logicExpresionNode));
	obj->block = this->checkBlock(scope, *(stmt.blockNode));

	tracer.decreaseNestingLevel();
	return obj;
}

std::shared_ptr<ir::Condition> SemanticCheck::checkCondition(ir::Scope& scope, ast::LogicExpression& condition)
{
	std::shared_ptr<ir::Condition> obj = std::make_shared<ir::Condition>();
	tracer.increaseNestingLevel("Checking condition statement");

	obj->operation = condition.operation;
	obj->negated = condition.negated;

	for (auto& operand : condition.operands)
	{
		if (operand->getType() == ast::Node::Type::LogicExpression)
		{
			obj->operands.push_back(this->checkCondition(scope, *(static_cast<ast::LogicExpression*>(operand.get())))); 
		}
		else if (operand->getType() == ast::Node::Type::Variable)
		{
			obj->operands.push_back(this->checkVariable(scope, *(static_cast<ast::Variable*>(operand.get()))));
		}
		else if (operand->getType() == ast::Node::Type::MathExpression)
		{
			std::cout << "MExepression" << std::endl;
			obj->operands.push_back(this->checkExpression(scope, *(static_cast<ast::MathExpression*>(operand.get()))));
		}
		else
		{
			std::string errorMsg("Invalid condition operand");
			throw std::exception(errorMsg.c_str());
		}
	}

	tracer.decreaseNestingLevel();
	return obj;
}

std::shared_ptr<ir::instructions::PrintfStatement> SemanticCheck::checkPrintfStatement(ir::Scope& scope, ast::PrintfStatement& printfStatement)
{
	std::shared_ptr<ir::instructions::PrintfStatement> obj = std::make_shared<ir::instructions::PrintfStatement>();
	tracer.increaseNestingLevel("Checking printf statement");
	obj->name = printfStatement.stringLiteral;
	tracer.decreaseNestingLevel();
	return obj;
}