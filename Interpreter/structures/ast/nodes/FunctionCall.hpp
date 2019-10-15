#ifndef TKOM_STRUCTURES_AST_NODES_FUNCTIONCALL_HPP
#define TKOM_STRUCTURES_AST_NODES_FUNCTIONCALL_HPP

#include "../AST.hpp"
#include <vector>

using MathExpression = tkom::structures::ast::MathExpression;
using Node = tkom::structures::ast::Node;

namespace tkom {
	namespace structures {
		namespace ast
		{
			class FunctionCall : public Node
			{
			public:
				std::string objectName;
				std::string functionName;
				std::vector<std::shared_ptr<MathExpression>> arguments;
				bool negated = false;

				void setObjectName(const std::string& objectName)
				{
					this->objectName = objectName;
				}

				void setFunctionName(const std::string& functionName)
				{
					this->functionName = functionName;
				}

				void setNegated()
				{
					this->negated = true;
				}

				void addArgument(const std::shared_ptr<MathExpression>& mathExpressionNode)
				{
					this->arguments.push_back(mathExpressionNode);
				}

				virtual Type getType()
				{
					return Node::Type::FunctionCall;
				}
			};
		}
	}
}

#endif