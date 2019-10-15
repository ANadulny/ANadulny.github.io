#ifndef TKOM_STRUCTURES_IR_EXPRESSION_HPP
#define TKOM_STRUCTURES_IR_EXPRESSION_HPP

#include <vector>
#include <memory>
#include <iostream>

#include "ExpressionOperand.hpp"
#include "../../modules/tokens/TokenType.hpp"

namespace tkom {
	namespace structures {
		namespace ir
		{
			struct Expression : public ExpressionOperand, public ConditionOperand
			{
				std::vector<tkom::modules::tokens::TokenType> operations;
				std::vector<std::shared_ptr<ExpressionOperand>> operands;

				
				virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
				{
					
					if (this->operations.size() == 0)
						return this->operands.at(0)->execute(scope, functions);

					std::shared_ptr<Literal> result = this->operands.at(0)->execute(scope, functions);
					
					unsigned int i = 0;
					for (auto& op : this->operations)
					{
						auto& it = this->operands.at(i + 1);
						i++;

						if (op == tkom::modules::tokens::TokenType::Plus)
						{
							*result += *(it->execute(scope, functions));
						}
						else if (op == tkom::modules::tokens::TokenType::Minus)
						{
							*result -= *(it->execute(scope, functions));
						}
						else if (op == tkom::modules::tokens::TokenType::Multiply)
						{
							*result *= *(it->execute(scope, functions));
						}
						else if (op == tkom::modules::tokens::TokenType::Divide)
						{
							*result /= *(it->execute(scope, functions));
						}
						else
						{
							std::string errMsg("Invalid expression operator");
							throw std::exception(errMsg.c_str());
						}
					}

					return result;
				}
			};
		}
	}
}

#endif