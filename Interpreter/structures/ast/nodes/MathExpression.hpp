#ifndef TKOM_STRUCTURES_AST_NODES_MATHEXPRESSION_HPP
#define TKOM_STRUCTURES_AST_NODES_MATHEXPRESSION_HPP

#include "../AST.hpp"
#include "../../../modules/tokens/TokenType.hpp"

using Node = tkom::structures::ast::Node;
using TokenType = tkom::modules::tokens::TokenType;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class MathExpression : public Node
			{
			public:
				std::vector<TokenType> operations;
				std::vector<ast::NodePtr> operands;
				bool negated = false;

				void addOperand(const ast::NodePtr& node)
				{
					this->operands.push_back(node);
				}

				void addOperator(const TokenType& operation)
				{
					this->operations.push_back(operation);
				}

				void setNegated() {
					this->negated = true;
				}

				virtual Type getType()
				{
					return Node::Type::MathExpression;
				}
			};
		}
	}
}

#endif