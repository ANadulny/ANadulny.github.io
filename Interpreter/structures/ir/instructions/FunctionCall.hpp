#ifndef TKOM_STRUCTURES_IR_INSTRUCTIONS_CALL_HPP
#define TKOM_STRUCTURES_IR_INSTRUCTIONS_CALL_HPP

#include <vector>
#include <memory>
#include <string>

#include "../Instruction.hpp"
#include "../../../modules/stdlib/StdLib.hpp"

namespace ir = tkom::structures::ir;
using StdLib = tkom::modules::StdLib;

namespace tkom {
	namespace structures {
		namespace ir {
			namespace instructions
			{
				struct FunctionCall : public ir::Instruction, public ExpressionOperand, public ConditionOperand
				{
					std::string name;
					std::string objectName = ""; // zamienic na variableName
					std::vector<std::shared_ptr<ir::Expression>> arguments;

					virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
					{
						std::vector<std::shared_ptr<ir::Literal>> concreteArguments;
						
						for (auto& it : this->arguments)
						{
							concreteArguments.push_back(it->execute(scope, functions));
						}

						if (functions.count(this->name) == 1)
						{
							return functions.at(this->name)->execute(nullptr, functions, concreteArguments);
						}
						else if (this->objectName != "")
						{
							//powinno nastapic sprawdzenie czy variable zostalo zadeklarowane
							concreteArguments.push_back(scope->getVariable(objectName));
							return StdLib::callObjectFunction(this->name, concreteArguments);
						}
						else
						{
							return StdLib::callFunction(this->name, concreteArguments);
						}
						return nullptr;
					}
				};
			}
		}
	}
}

#endif