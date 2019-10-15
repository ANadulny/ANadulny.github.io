#ifndef TKOM_STRUCTURES_AST_NODES_RETURNSTATEMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_RETURNSTATEMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class ReturnStatement : public Node
			{
			public:
				std::shared_ptr<MathExpression> mathExpressionNode;

				void setValue(const std::shared_ptr<MathExpression>& mathExpressionNode)
				{
					this->mathExpressionNode = mathExpressionNode;
				}

				virtual Type getType()
				{
					return Node::Type::ReturnStatement;
				}
			};
		}
	}
}

#endif