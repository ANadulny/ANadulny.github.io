#include "Parser.hpp"

#include "../lexer/Lexer.hpp"

#include <iostream>
#include <limits>
#include <sstream>

using Parser = tkom::modules::Parser;
using Lexer = tkom::modules::Lexer;

Parser::Parser(Lexer& lexer) : lexer(lexer) {
	getNextToken();
}

std::shared_ptr<ast::Program> Parser::parse()
{
	this->tracer.resetNestingLevel();

	std::shared_ptr<ast::Program> syntaxTree = std::make_shared<ast::Program>();
	std::shared_ptr<ast::FunctionDef> function;

	this->tracer.printMessage("Starting parser tracing...");
	while ((function = this->parseFunction()))
		syntaxTree->addFunction(function);

	this->tracer.printMessage("Trace ended...");
	return syntaxTree;
}

bool Parser::isAcceptable(const Token& token, const std::initializer_list<TokenType>& acceptable) const
{
	for (auto& it : acceptable) {
		if (token.type == it)
			return true;
	}

	return false;
}

Token Parser::accept(const std::initializer_list<TokenType>& acceptable)
{
	Token actualToken = this->token;

	if (this->isAcceptable(token, acceptable)) {
		getNextToken();
	}
	else {
		std::string errorMsg("Unexpected token: " + tkom::modules::tokens::getTokenTypeName(token.type) +
			" (Line: " + std::to_string(token.line) + " Position: " + std::to_string(token.position) + ")\n" +
			"Expected tokens: " + getStringTokenList(acceptable) + "\n"
		);
		throw std::exception(errorMsg.c_str());
	}

	return actualToken;
}

std::string Parser::getStringTokenList(const std::initializer_list<TokenType>& acceptable)
{
	std::stringstream ss;
	for (auto& it : acceptable) {
		ss << getTokenTypeName(it) << "  ";
	}
	std::string s = ss.str();
	return s;
}

void Parser::getNextToken()
{
	this->token = this->lexer.nextToken();
}

std::shared_ptr<ast::FunctionDef> Parser::parseFunction()
{
	std::shared_ptr<ast::FunctionDef> node = std::make_shared<ast::FunctionDef>();
	this->tracer.increaseNestingLevel("Parsing function");

	Token tempToken = this->accept({ TokenType::Function, TokenType::EndOfFile });

	if (tempToken.type == TokenType::EndOfFile)
	{
		this->tracer.decreaseNestingLevel();
		this->tracer.printMessage("EOF");
		return nullptr;
	}

	tempToken = this->accept({ TokenType::Identifier });
	node->setName(tempToken.value);
	node->setParameters(this->parseParameters());
	node->setBlock(this->parseStatementBlock());

	this->tracer.decreaseNestingLevel();
	return node;
}

std::vector<std::string> Parser::parseParameters()
{
	std::vector<std::string> parametersNames;
	this->tracer.increaseNestingLevel("Parsing parameters");

	this->accept({ TokenType::ParenthOpen });
	Token tempToken = this->accept({ TokenType::ParenthClose, TokenType::Identifier });

	while (tempToken.type != TokenType::ParenthClose)
	{
		parametersNames.push_back(tempToken.value);
		tempToken = this->accept({ TokenType::ParenthClose, TokenType::Comma });
		if (tempToken.type == TokenType::Comma)
			tempToken = this->accept({ TokenType::Identifier });
	}

	this->tracer.decreaseNestingLevel();
	return parametersNames;
}

std::shared_ptr<ast::StatementBlock> Parser::parseStatementBlock()
{
	std::shared_ptr<ast::StatementBlock> node = std::make_shared<ast::StatementBlock>();
	this->tracer.increaseNestingLevel("Parsing statement block");

	this->accept({ TokenType::CurlyBracketOpen });
	Token tempToken;

	do
	{
		tempToken = this->accept({ TokenType::If,
									TokenType::While,
									TokenType::Return,
									TokenType::Var,
									TokenType::Identifier,
									TokenType::Continue,
									TokenType::Break,
									TokenType::Printf,
									TokenType::CurlyBracketClose
			});

		switch (tempToken.type)
		{
		case TokenType::If:
			node->addInstruction(this->parseIfStatement());
			break;
		case TokenType::While:
			node->addInstruction(this->parseWhileStatement());
			break;
		case TokenType::Return:
			node->addInstruction(this->parseReturnStatement());
			break;
		case TokenType::Var:
			node->addInstruction(this->parseInitStatement());
			break;
		case TokenType::Identifier:
			node->addInstruction(this->parseAssignmentOrFunCall(tempToken));
			break;
		case TokenType::Continue:
		case TokenType::Break:
			node->addInstruction(this->parseLoopJump(tempToken.type));
			break;
		case TokenType::Printf:
			node->addInstruction(this->parsePrintfStatement());
			break;
		default:
			break;
		}
	} while (tempToken.type != TokenType::CurlyBracketClose);

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::IfStatement> Parser::parseIfStatement()
{
	std::shared_ptr<ast::IfStatement> node = std::make_shared<ast::IfStatement>();
	this->tracer.increaseNestingLevel("Parsing if statement");

	this->accept({ TokenType::ParenthOpen });
	node->setLogicExpresion(this->parseLogicExpression());

	this->accept({ TokenType::ParenthClose });
	node->setIfBlock(this->parseStatementBlock());

	if (this->token.type == TokenType::Else)
	{
		this->accept({ TokenType::Else });
		node->setElseBlock(this->parseStatementBlock());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::WhileStatement> Parser::parseWhileStatement()
{
	std::shared_ptr<ast::WhileStatement> node = std::make_shared<ast::WhileStatement>();
	this->tracer.increaseNestingLevel("Parsing while statement");

	this->accept({ TokenType::ParenthOpen });
	node->setLogicExpresion(this->parseLogicExpression());

	this->accept({ TokenType::ParenthClose });
	node->setBlock(this->parseStatementBlock());

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::ReturnStatement> Parser::parseReturnStatement()
{
	std::shared_ptr<ast::ReturnStatement> node = std::make_shared<ast::ReturnStatement>();
	this->tracer.increaseNestingLevel("Parsing return statement");

	node->setValue(this->parseMathExpression());
	this->accept({ TokenType::Semicolon });

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::InitStatement> Parser::parseInitStatement()
{
	std::shared_ptr<ast::InitStatement> node = std::make_shared<ast::InitStatement>();
	this->tracer.increaseNestingLevel("Parsing init statement");

	Token tempToken = this->accept({ TokenType::Identifier });
	node->setName(tempToken.value);

	if (this->token.type == TokenType::Assignment)
	{
		this->accept({ TokenType::Assignment });
		node->setValue(this->parseMathExpression());
	}

	this->accept({ TokenType::Semicolon });

	this->tracer.decreaseNestingLevel();
	return node;
}

ast::NodePtr Parser::parseAssignmentOrFunCall(const Token& identifier)
{
	ast::NodePtr node;
	this->tracer.increaseNestingLevel("Parsing assignment or function call");

	Token tempToken;

	if (this->token.type == TokenType::Dot)
	{
		this->accept({ TokenType::Dot });
		tempToken = this->accept({ TokenType::Identifier });
		node = this->parseFunctionCall(identifier.value, tempToken.value);
	}
	else if (this->token.type == TokenType::ParenthOpen) {
		node = this->parseFunctionCall(identifier.value);
	}
	else {
		node = this->parseAssignement(identifier);
	}

	this->accept({ TokenType::Semicolon });

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::Assignment> Parser::parseAssignement(const Token& identifier)
{
	std::shared_ptr<ast::Assignment> node = std::make_shared<ast::Assignment>();
	this->tracer.increaseNestingLevel("Parsing assignment ");

	node->setVariable(this->parseVariable(identifier));
	this->accept({ TokenType::Assignment });
	node->setValue(this->parseMathExpression());

	this->tracer.decreaseNestingLevel();
	return node;
};

std::shared_ptr<ast::LoopJump> Parser::parseLoopJump(const TokenType& type)
{
	std::shared_ptr<ast::LoopJump> node = std::make_shared<ast::LoopJump>();
	this->tracer.increaseNestingLevel("Parsing loop jump");

	node->setType(type);
	this->accept({ TokenType::Semicolon });

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::PrintfStatement> Parser::parsePrintfStatement()
{
	std::shared_ptr<ast::PrintfStatement> node = std::make_shared<ast::PrintfStatement>();
	this->tracer.increaseNestingLevel("Parsing printf statement");

	this->accept({ TokenType::ParenthOpen });
	Token tempToken = this->accept({ TokenType::StringLiteral });

	node->setStringLiteral(tempToken.value);

	this->accept({ TokenType::ParenthClose });
	this->accept({ TokenType::Semicolon });

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::FunctionCall> Parser::parseFunctionCall(const std::string& identifier, const std::string& secondIdentifier)
{
	std::shared_ptr<ast::FunctionCall> node = std::make_shared<ast::FunctionCall>();
	this->tracer.increaseNestingLevel("Parsing function call");

	if (secondIdentifier.length() > 0) {
		node->setObjectName(identifier);
		node->setFunctionName(secondIdentifier);
	}
	else {
		node->setFunctionName(identifier);
	}

	this->accept({ TokenType::ParenthOpen });

	if (this->token.type != TokenType::ParenthClose)
	{
		node->addArgument(this->parseMathExpression());

		while (this->token.type != TokenType::ParenthClose)
		{
			this->accept({ TokenType::Comma });
			node->addArgument(this->parseMathExpression());
		}
	}

	this->accept({ TokenType::ParenthClose });
	this->tracer.decreaseNestingLevel("  + function call");
	return node;
}

std::shared_ptr<ast::Variable> Parser::parseVariable(const Token& identifierToken)
{
	std::shared_ptr<ast::Variable> node = std::make_shared<ast::Variable>();
	this->tracer.increaseNestingLevel("Parsing variable");

	if (identifierToken.type == TokenType::Identifier) {
		node->setName(identifierToken.value);
	}
	else {
		//TODO
		std::cout << "czy moze wystapic ta sytuacja ???" << std::endl;
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::MathExpression> Parser::parseMathExpression()
{
	std::shared_ptr<ast::MathExpression> node = std::make_shared<ast::MathExpression>();
	this->tracer.increaseNestingLevel("Parsing math expression");

	node->addOperand(this->parseMultiplicativeExpression());

	while (this->token.type == TokenType::Plus || this->token.type == TokenType::Minus)
	{
		Token tempToken = this->accept({ TokenType::Plus, TokenType::Minus });
		node->addOperator(tempToken.type);
		node->addOperand(this->parseMultiplicativeExpression());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::MathExpression> Parser::parseMultiplicativeExpression()
{
	std::shared_ptr<ast::MathExpression> node = std::make_shared<ast::MathExpression>();
	this->tracer.increaseNestingLevel("Parsing multiplicative expression");

	node->addOperand(this->parseBaseMathExpression());

	while (this->token.type == TokenType::Multiply || this->token.type == TokenType::Divide)
	{
		Token tempToken = this->accept({ TokenType::Multiply, TokenType::Divide });
		node->addOperator(tempToken.type);
		node->addOperand(this->parseBaseMathExpression());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

ast::NodePtr Parser::parseBaseMathExpression()
{
	this->tracer.increaseNestingLevel("Parsing base math expression");
	bool negate = false;
	if (this->token.type == TokenType::Minus) {
		this->accept({ TokenType::Minus });
		negate = true;
	}

	if (this->token.type == TokenType::ParenthOpen)
	{
		this->accept({ TokenType::ParenthOpen });
		auto node = this->parseMathExpression();
		if (negate)
			node->setNegated();
		this->accept({ TokenType::ParenthClose });
		this->tracer.decreaseNestingLevel();
		return node;
	}

	if (this->token.type == TokenType::Identifier)
	{
		Token tempFirstToken = this->accept({ TokenType::Identifier });
		if (this->token.type == TokenType::Dot)
		{
			this->accept({ TokenType::Dot });
			Token tempSecondToken = this->accept({ TokenType::Identifier });
			auto node = this->parseFunctionCall(tempFirstToken.value, tempSecondToken.value);
			if (negate)
				node->setNegated();
			this->tracer.decreaseNestingLevel();
			return node;
		}
		else if (this->token.type == TokenType::ParenthOpen) {
			auto node = this->parseFunctionCall(tempFirstToken.value);
			if (negate)
				node->setNegated();
			this->tracer.decreaseNestingLevel();
			return node;
		}
		else {
			auto node = this->parseVariable(tempFirstToken);
			if (negate)
				node->setNegated();
			this->tracer.decreaseNestingLevel();
			return node;
		}
	}

	auto node = this->parseNumberLiteral();

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::NumberLiteral> Parser::parseNumberLiteral()
{
	std::shared_ptr<ast::NumberLiteral> node = std::make_shared<ast::NumberLiteral>();
	this->tracer.increaseNestingLevel("Parsing number literal");

	double value;
	bool negative = false;

	if (this->token.type == TokenType::Minus) {
		this->accept({ TokenType::Minus });
		negative = true;
	}

	Token tempToken = this->accept({ TokenType::NumberLiteral });
	value = std::stod(tempToken.value);

	if (negative)
		value *= -1;

	node->setValue(value);
	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::LogicExpression> Parser::parseLogicExpression()
{
	std::shared_ptr<ast::LogicExpression> node = std::make_shared<ast::LogicExpression>();
	this->tracer.increaseNestingLevel("Parsing logic expression");

	node->addOperand(this->parseAndExpression());

	while (this->token.type == TokenType::Or)
	{
		this->accept({ TokenType::Or });
		node->setOperator(TokenType::Or);
		node->addOperand(this->parseAndExpression());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::LogicExpression> Parser::parseAndExpression()
{
	std::shared_ptr<ast::LogicExpression> node = std::make_shared<ast::LogicExpression>();
	this->tracer.increaseNestingLevel("Parsing and expression");

	node->addOperand(this->parseRelationalExpression());

	while (this->token.type == TokenType::And)
	{
		this->accept({ TokenType::And });
		node->setOperator(TokenType::And);
		node->addOperand(this->parseRelationalExpression());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

std::shared_ptr<ast::LogicExpression> Parser::parseRelationalExpression()
{
	std::shared_ptr<ast::LogicExpression> node = std::make_shared<ast::LogicExpression>();
	this->tracer.increaseNestingLevel("Parsing relation expression");

	node->addOperand(this->parseBaseLogicExpression());

	if (this->token.type == TokenType::Equality || this->token.type == TokenType::Inequality ||
		this->token.type == TokenType::LessThan || this->token.type == TokenType::GreaterThan ||
		this->token.type == TokenType::LessOrEqual || this->token.type == TokenType::GreaterOrEqual)
	{
		Token tempToken = this->accept({ TokenType::Equality, TokenType::Inequality, TokenType::LessThan,
										 TokenType::GreaterThan, TokenType::LessOrEqual, TokenType::GreaterOrEqual });
		node->setOperator(tempToken.type);
		node->addOperand(this->parseBaseLogicExpression());
	}

	this->tracer.decreaseNestingLevel();
	return node;
}

ast::NodePtr Parser::parseBaseLogicExpression()
{
	this->tracer.increaseNestingLevel("Parsing base logic expression");
	bool negate = false;

	if (this->token.type == TokenType::Negation)
	{
		this->accept({ TokenType::Negation });
		negate = true;
	}

	if (this->token.type == TokenType::ParenthOpen)
	{
		this->accept({ TokenType::ParenthOpen });
		auto node = this->parseLogicExpression();
		if (negate)
			node->setNegated();
		this->accept({ TokenType::ParenthClose });
		this->tracer.decreaseNestingLevel();
		return node;
	}

	auto node = this->parseMathExpression();
	if (negate)
		node->setNegated();

	this->tracer.decreaseNestingLevel();
	return node;
}