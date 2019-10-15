#ifndef TKOM_STRUCTURES_AST_NODES_IFSTATEMENT_HPP
#define TKOM_STRUCTURES_AST_NODES_IFSTATEMENT_HPP

#include "../AST.hpp"

using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class StatementBlock;
			class LogicExpression;

			class IfStatement : public Node
			{
			public:
				std::shared_ptr<LogicExpression> logicExpresionNode;
				std::shared_ptr<StatementBlock> ifBlockNode;
				std::shared_ptr<StatementBlock> elseBlockNode;

				void setLogicExpresion(const std::shared_ptr<LogicExpression>& logicExpresionNode) 
				{
					this->logicExpresionNode = logicExpresionNode;
				}

				void setIfBlock(const std::shared_ptr<StatementBlock>& ifBlockNode)
				{
					this->ifBlockNode = ifBlockNode;
				}

				void setElseBlock(const std::shared_ptr<StatementBlock>& elseBlockNode)
				{
					this->elseBlockNode = elseBlockNode;
				}

				virtual Type getType()
				{
					return Node::Type::IfStatement;
				}
			};
		}
	}
}

#endif