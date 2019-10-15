#ifndef TKOM_STRUCTURES_IR_PRINTFSTATEMENT_HPP
#define TKOM_STRUCTURES_IR_PRINTFSTATEMENT_HPP

#include <memory>
#include "../Instruction.hpp"

namespace ir = tkom::structures::ir;

namespace tkom {
	namespace structures {
		namespace ir {
			namespace instructions
			{
				struct PrintfStatement : public ir::Instruction
				{
					std::string name;

					virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
					{
						std::cout << this->name << std::endl;
						return nullptr;
					}
				};
			}
		}
	}
}
#endif