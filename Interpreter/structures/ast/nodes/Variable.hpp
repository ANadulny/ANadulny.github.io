#ifndef TKOM_STRUCTURES_AST_NODES_VARIABLE_HPP
#define TKOM_STRUCTURES_AST_NODES_VARIABLE_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class Variable : public Node
			{
			public:
				std::string variableName;
				bool negated = false;

				void setName(const std::string& name)
				{
					this->variableName = name;
				}

				void setNegated() 
				{
					this->negated = true;
				}

				virtual Type getType()
				{
					return Node::Type::Variable;
				}
			};
		}
	}
}

#endif