#ifndef TKOM_STRUCTURES_IR_INSTRUCTIONS_RETURN_HPP
#define TKOM_STRUCTURES_IR_INSTRUCTIONS_RETURN_HPP

#include <memory>

#include "../Instruction.hpp"

namespace ir = tkom::structures::ir;

namespace tkom {
	namespace structures {
		namespace ir {
			namespace instructions
			{
				struct Return : public ir::Instruction
				{
					std::shared_ptr<ir::Expression> value;
					
					virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
					{
						return this->value->execute(scope, functions);
					}

					virtual bool canDoReturn()
					{
						return true;
					}
				};
			}
		}
	}
}

#endif