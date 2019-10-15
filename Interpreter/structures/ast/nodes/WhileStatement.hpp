#ifndef TKOM_STRUCTURES_AST_NODES_WHILESTATEMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_WHILESTATEMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class WhileStatement : public Node
			{
			public:
				std::shared_ptr<LogicExpression> logicExpresionNode;
				std::shared_ptr<StatementBlock> blockNode;

				void setLogicExpresion(const std::shared_ptr<LogicExpression>& logicExpresionNode)
				{
					this->logicExpresionNode = logicExpresionNode;
				}

				void setBlock(const std::shared_ptr<StatementBlock>& blockNode)
				{
					this->blockNode = blockNode;
				}

				virtual Type getType()
				{
					return Node::Type::WhileStatement;
				}
			};
		}
	}
}

#endif