#ifndef TKOM_STRUCTURES_AST_NODES_PROGRAM_HPP
#define TKOM_STRUCTURES_AST_NODES_PROGRAM_HPP

#include "../AST.hpp"
#include <iostream>

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class FunctionDef;

			class Program : public Node
			{
			public:
				std::vector<std::shared_ptr<FunctionDef>> functions = {};

				void addFunction(const std::shared_ptr<FunctionDef>& function)
				{
					this->functions.push_back(function);
				}

				virtual Type getType()
				{
					return Node::Type::Program;
				}

			};
		}
	}
}

#endif