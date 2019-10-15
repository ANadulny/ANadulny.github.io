#ifndef TKOM_MODULES_PARSER_HPP
#define TKOM_MODULES_PARSER_HPP

#include <initializer_list>

#include "../tokens/Token.hpp"
#include "../tokens/TokenType.hpp"

#include "../tracer/Tracer.hpp"
#include "../../structures/ast/AST.hpp"

using Token = tkom::modules::tokens::Token;
using TokenType = tkom::modules::tokens::TokenType;
namespace ast = tkom::structures::ast;

namespace tkom {
	namespace modules
	{
		class Lexer;

		class Parser
		{
		public:
			Parser(Lexer& lexer);
			std::shared_ptr<ast::Program> parse();

		private:
			Tracer tracer = Tracer();
			Lexer& lexer;
			Token token;

			bool isAcceptable(const Token& token, const std::initializer_list<TokenType>& acceptable) const;
			Token accept(const std::initializer_list<TokenType>& acceptable);

			std::string getStringTokenList(const std::initializer_list<TokenType>& acceptable);
			void getNextToken();

			// Decomposition procedures
			std::shared_ptr<ast::FunctionDef> parseFunction();
			std::vector<std::string> parseParameters();
			std::shared_ptr<ast::StatementBlock> parseStatementBlock();

			std::shared_ptr<ast::IfStatement> parseIfStatement();
			std::shared_ptr<ast::WhileStatement> parseWhileStatement();
			std::shared_ptr<ast::ReturnStatement> parseReturnStatement();
			std::shared_ptr<ast::InitStatement> parseInitStatement();
			ast::NodePtr parseAssignmentOrFunCall(const Token& identifier);
			std::shared_ptr<ast::LoopJump> parseLoopJump(const TokenType& type);
			std::shared_ptr<ast::PrintfStatement> parsePrintfStatement();

			std::shared_ptr<ast::Assignment> parseAssignement(const Token& identifier);

			std::shared_ptr<ast::FunctionCall> parseFunctionCall(const std::string& identifier, const std::string& secondIdentifier = "");
			std::shared_ptr<ast::Variable> parseVariable(const Token& firstToken);
			std::shared_ptr<ast::NumberLiteral> parseNumberLiteral();

			std::shared_ptr<ast::MathExpression> parseMathExpression();
			std::shared_ptr<ast::MathExpression> parseMultiplicativeExpression();
			ast::NodePtr parseBaseMathExpression();

			std::shared_ptr<ast::LogicExpression> parseLogicExpression();
			std::shared_ptr<ast::LogicExpression> parseAndExpression();
			std::shared_ptr<ast::LogicExpression> parseRelationalExpression();

			ast::NodePtr parseBaseLogicExpression();
		};
	}
}

#endif