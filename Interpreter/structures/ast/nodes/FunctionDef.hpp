#ifndef TKOM_STRUCTURES_AST_NODES_FUNCTIONDEF_HPP
#define TKOM_STRUCTURES_AST_NODES_FUNCTIONDEF_HPP

#include "../AST.hpp"

#include <vector>
#include <string>

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class StatementBlock;

			class FunctionDef : public Node
			{
			public:
				std::string name;
				std::vector<std::string> parameters;
				std::shared_ptr<StatementBlock> blockNode;

				void setName(const std::string& name)
				{
					this->name = name;
				}

				void setParameters(const std::vector<std::string>& parameters)
				{
					this->parameters = parameters;
				}

				void setBlock(const std::shared_ptr<StatementBlock>& blockNode)
				{
					//this->blockNode = std::move(blockNode);
					this->blockNode = blockNode;
				}

				virtual Type getType()
				{
					return Node::Type::FunctionDef;
				}
			};
		}
	}
}

#endif