#ifndef TKOM_MODULES_SEMCHECK_HPP
#define TKOM_MODULES_SEMCHECK_HPP

#include "../parser/Parser.hpp"
#include "../../structures/ir/includes.hpp"

namespace ir = tkom::structures::ir;
namespace ast = tkom::structures::ast;

namespace tkom {
	namespace modules {
		class SemanticCheck
		{
	
		public:
			std::vector<std::shared_ptr<ir::Function>> check(const std::shared_ptr<ast::Program>& syntaxTree);
			
		private:
			Tracer tracer;
			std::shared_ptr<ast::Program> syntaxTree;
			std::unordered_map<std::string, std::shared_ptr<ir::Function>> definedFunctions;
	
			void scanFunctionDefinitions();
			void checkMain();
			std::vector<std::shared_ptr<ir::Function>> traverseTree();
			std::shared_ptr<ir::Function> checkFunction(ast::FunctionDef& functionDef);
			std::shared_ptr<ir::Block> checkBlock(ir::Scope& scope, ast::StatementBlock& blockNode);
			
			void checkVarDeclaration(ir::Scope& scope, const std::string& name);
			std::shared_ptr<ir::instructions::Assignment> checkAssignment(ir::Scope& scope, const std::string& variable, ast::MathExpression& mathExpression);
			std::shared_ptr<ir::instructions::Assignment> checkAssignment(ir::Scope& scope, ast::Variable& variable, ast::MathExpression& mathExpression);
			std::shared_ptr<ir::instructions::FunctionCall> checkFunctionCall(ir::Scope& scope, ast::FunctionCall& functionCall);
			std::shared_ptr<ir::Literal> checkLiteral(ir::Scope& scope, ast::NumberLiteral& numberLiteral);
			std::shared_ptr<ir::Expression> checkExpression(ir::Scope& scope, ast::MathExpression& mathExpression);
			std::shared_ptr<ir::Variable> checkVariable(ir::Scope& scope, ast::Variable& variable);
			std::shared_ptr<ir::instructions::Return> checkReturnStatement(ir::Scope& scope, ast::MathExpression& mathExpression);
			std::shared_ptr<ir::instructions::IfStatement> checkIfStatement(ir::Scope& scope, ast::IfStatement& ifStatement);
			std::shared_ptr<ir::instructions::WhileStatement> checkWhileStatement(ir::Scope& scope, ast::WhileStatement& whileStatement);
			std::shared_ptr<ir::Condition> checkCondition(ir::Scope& scope, ast::LogicExpression& logicExpression);
			std::shared_ptr<ir::instructions::PrintfStatement> checkPrintfStatement(ir::Scope& scope, ast::PrintfStatement& printfStatement);
			
		};
	}
}

#endif