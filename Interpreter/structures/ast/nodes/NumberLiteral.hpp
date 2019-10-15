#ifndef TKOM_STRUCTURES_AST_NODETYPES_NUMBERLITERAL_HPP
#define TKOM_STRUCTURES_AST_NODETYPES_NUMBERLITERAL_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class NumberLiteral : public Node {
			public:
				double value;

				void setValue(double value) 
				{
					this->value = value;
				}

				virtual Type getType() 
				{
					return Type::NumberLiteral;
				}
			};
		}
	}
}
#endif