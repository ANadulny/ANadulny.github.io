#ifndef TKOM_STRUCTURES_AST_HPP
#define TKOM_STRUCTURES_AST_HPP

#include <memory>

namespace tkom {
	namespace structures {
		namespace ast 
		{
			class Node
			{
			protected:
				std::weak_ptr<Node> parent;

			public:
				enum class Type {
					Assignment,
					FunctionCall,
					FunctionDef,
					IfStatement,
					InitStatement,
					LogicExpression,
					LoopJump,
					MathExpression,
					NumberLiteral,
					PrintfStatement,
					Program,
					ReturnStatement,
					StatementBlock,
					Variable,
					WhileStatement
				};

				virtual Type getType() = 0;
			};

			typedef std::shared_ptr<Node> NodePtr;
		}
	}
}

#include "nodes/Assignment.hpp"
#include "nodes/FunctionCall.hpp"
#include "nodes/FunctionDef.hpp"
#include "nodes/IfStatement.hpp"
#include "nodes/InitStatement.hpp"
#include "nodes/LogicExpression.hpp"
#include "nodes/LoopJump.hpp"
#include "nodes/MathExpression.hpp"
#include "nodes/NumberLiteral.hpp"
#include "nodes/PrintfStatement.hpp"
#include "nodes/Program.hpp"
#include "nodes/ReturnStatement.hpp"
#include "nodes/StatementBlock.hpp"
#include "nodes/Variable.hpp"
#include "nodes/WhileStatement.hpp"

#endif