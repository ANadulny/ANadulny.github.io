#ifndef TKOM_STRUCTURES_AST_NODES_PRINTFSTATEMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_PRINTFSTATEMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class PrintfStatement : public Node
			{
			public:
				std::string stringLiteral;

				void setStringLiteral(const std::string& string)
				{
					this->stringLiteral = string;
				}

				virtual Type getType()
				{
					return Node::Type::PrintfStatement;
				}
			};
		}
	}
}

#endif