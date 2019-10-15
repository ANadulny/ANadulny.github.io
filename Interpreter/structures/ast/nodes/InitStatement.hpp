#ifndef TKOM_STRUCTURES_AST_NODES_INITSTATEMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_INITSTATEMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class InitStatement : public Node
			{
			public:
				std::string name;
				std::shared_ptr<MathExpression> mathExpressionNode;

				void setName(const std::string& name)
				{
					this->name = name;
				}

				void setValue(const std::shared_ptr<MathExpression>& mathExpressionNode)
				{
					this->mathExpressionNode = mathExpressionNode;
				}

				virtual Type getType()
				{
					return Node::Type::InitStatement;
				}
			};
		}
	}
}

#endif