#ifndef TKOM_STRUCTURES_AST_NODES_ASSIGNMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_ASSIGNMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class Variable;
			class MathExpression;

			class Assignment : public Node
			{
			public:
				std::shared_ptr<Variable> variable;
				std::shared_ptr<MathExpression> value;

				void setVariable(const std::shared_ptr<Variable>& variable)
				{
					this->variable = variable;
				}

				void setValue(const std::shared_ptr<MathExpression>& value)
				{
					this->value = value;
				}

				virtual Type getType()
				{
					return Node::Type::Assignment;
				}
			};
		}
	}
}

#endif