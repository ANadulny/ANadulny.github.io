#ifndef TKOM_STRUCTURES_IR_FUNCTION_HPP
#define TKOM_STRUCTURES_IR_FUNCTION_HPP

#include <vector>
#include <memory>
#include <string>

#include "Block.hpp"
#include "Literal.hpp"

namespace tkom {
	namespace structures {
		namespace ir
		{
			struct Function : public Block
			{
				typedef std::shared_ptr<Function> ptr;
				std::string name;

				virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
				{
					std::string errMsg("Cannot execute function without parameters, fatal error");
					throw std::exception(errMsg.c_str());
				}

				virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions, std::vector<std::shared_ptr<ir::Literal>> arguments)
				{
					auto thisScope = this->scope.instantiate(scope);
					unsigned int argIdx = 0;
					for (auto& argument : arguments)
					{
						std::shared_ptr<ir::Literal> copy = std::make_shared<ir::Literal>();
						copy->data = argument->data;

						thisScope.variables.at(thisScope.varOrder.at(argIdx)) = copy;
						argIdx++;
					}

					for (auto& it : this->instructions)
					{
						auto result = it->execute(&thisScope, functions);
						if (result && result->loopJump)
						{
							std::string errMsg("Break/continue outside of loop");
							throw std::exception(errMsg.c_str());
						}
						if (result && it->canDoReturn())
							return result;
					}

					std::string errMsg("No return, fatal error");
					throw std::exception(errMsg.c_str());
				};
			};
		}
	}
}

#endif