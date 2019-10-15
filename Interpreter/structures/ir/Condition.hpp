#ifndef TKOM_STRUCTURES_IR_CONDITION_HPP
#define TKOM_STRUCTURES_IR_CONDITION_HPP

#include <vector>
#include <memory>
#include <iostream>

#include "ConditionOperand.hpp"
#include "Literal.hpp"
#include "../../modules/tokens/TokenType.hpp"

namespace tkom {
	namespace structures {
		namespace ir
		{
			struct Condition : public ConditionOperand
			{
				bool negated = false;
				tkom::modules::tokens::TokenType operation = tkom::modules::tokens::TokenType::Undefined;
				std::vector<std::shared_ptr<ConditionOperand>> operands;


				virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
				{
					
					if (this->operation == tkom::modules::tokens::TokenType::Undefined)
					{
						if (!this->negated)
						{
							return this->operands.at(0)->execute(scope, functions);
						}
						else
						{
							auto result = std::make_shared<Literal>();
							result->castedToBool = true;
							result->data = { { this->operands.at(0)->execute(scope, functions)->isTruthy() ? 0.0 : 1.0 } };
							return result;
						}
					}

					else if (this->operation == tkom::modules::tokens::TokenType::Or)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;
						for (auto& it : this->operands)
						{
							if (it->execute(scope, functions)->isTruthy())
							{
								result->data = { 1.0 };
								return result;
							}
						}
						result->data = { 0.0 };
						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::And)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;
						for (auto& it : this->operands)
						{
							if (!it->execute(scope, functions)->isTruthy())
							{
								result->data = { 0.0 };
								return result;
							}
						}
						result->data = { 1.0 };
						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::Equality)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (left->castedToBool && right->castedToBool)
						{
							result->data = { { left->isTruthy() == right->isTruthy() ? 1.0 : 0.0 } };
						}
						else if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left == *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Tried to compare matrix with bool matrix");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::Inequality)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (left->castedToBool && right->castedToBool)
						{
							result->data = { { left->isTruthy() != right->isTruthy() ? 1.0 : 0.0 } };
						}
						else if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left != *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Tried to compare matrix with bool matrix");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::LessThan)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left < *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Cannot compare bool matrices");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::LessOrEqual)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left <= *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Cannot compare bool matrices");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::GreaterThan)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left > *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Cannot compare bool matrices");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else if (this->operation == tkom::modules::tokens::TokenType::GreaterOrEqual)
					{
						auto result = std::make_shared<ir::Literal>();
						result->castedToBool = true;

						auto left = this->operands.at(0)->execute(scope, functions);
						auto right = this->operands.at(1)->execute(scope, functions);

						if (!left->castedToBool && !right->castedToBool)
						{
							result->data = { { *left >= *right ? 1.0 : 0.0 } };
						}
						else
						{
							std::string errorMsg("Cannot compare bool matrices");
							throw std::exception(errorMsg.c_str());
						}

						return result;
					}
					else
					{
						std::string errorMsg("Invalid condition operator");
						throw std::exception(errorMsg.c_str());
					} 
					return nullptr;
				}
			};
		}
	}
}

#endif