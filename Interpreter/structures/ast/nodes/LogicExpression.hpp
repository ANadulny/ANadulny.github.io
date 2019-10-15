#ifndef TKOM_STRUCTURES_AST_NODES_LOGICEXPRESSION_HPP
#define TKOM_STRUCTURES_AST_NODES_LOGICEXPRESSION_HPP

#include "../AST.hpp"
#include "../../../modules/tokens/TokenType.hpp"

using Node = tkom::structures::ast::Node;
using TokenType = tkom::modules::tokens::TokenType;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class LogicExpression : public Node
			{
			public:
				TokenType operation = TokenType::Undefined;
				std::vector<ast::NodePtr> operands;
				bool negated = false;

				void addOperand(const ast::NodePtr& node)
				{
					this->operands.push_back(node);
				}

				void setOperator(const TokenType& operation)
				{
					this->operation = operation;
				}

				void setNegated()
				{
					this->negated = true;
				}

				bool isNegated()
				{
					return this->negated;
				}

				virtual Type getType()
				{
					return Node::Type::LogicExpression;
				}
			};
		}
	}
}

#endif