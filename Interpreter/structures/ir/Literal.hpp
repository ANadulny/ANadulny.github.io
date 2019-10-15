#ifndef TKOM_STRUCTURES_IR_LITERAL_HPP
#define TKOM_STRUCTURES_IR_LITERAL_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <utility>

#include "ConditionOperand.hpp"
#include "ExpressionOperand.hpp"

namespace tkom {
	namespace structures {
		namespace ir
		{
			struct Literal : public ConditionOperand, public ExpressionOperand
			{
				std::vector<double> data = {};
				double determinant = 0;
				bool castedToBool = false;
				bool loopJump = false;
				bool isBreak = false;
				
				virtual std::shared_ptr<Literal> execute(ScopeInst* scope, std::unordered_map<std::string, std::shared_ptr<Function>>& functions)
				{
					std::shared_ptr<Literal> copy = std::make_shared<Literal>();
					copy->data = this->data;
					copy->determinant = this->determinant;
					return copy;
				}
				
				const int getSize() const
				{
					if (this->data.size() != 1 && this->data.size() != 4) {
						std::string errMsg("Vector size can be only 1 or 4");
						throw std::exception(errMsg.c_str());
					}

					return this->data.size();
				}

				void setDeterminant()
				{
					if (this->data.size() != 1 && this->data.size() != 4) {
						std::string errMsg("Can not set determinant cause wrong vector size");
						throw std::exception(errMsg.c_str());
					}
					updateDeterminant();
				}

				virtual bool isTruthy()
				{
					for (auto& it : this->data)
					{
						if (it != 0)
							return true;
					}

					return false;
				}
				
				bool operator==(const Literal& rhs)
				{
					this->checkSizes(rhs);

					for (auto x = 0; x < this->data.size(); x++)
					{
						if (this->data.at(x) != rhs.data.at(x))
							return false;
					}

					return true;
				}

				bool operator!=(const Literal& rhs)
				{
					return !((*this) == rhs);
				}

				bool operator<(const Literal& rhs)
				{
					this->protectRelationOp(rhs);
					return this->determinant < rhs.determinant;
				}
				bool operator<=(const Literal& rhs)
				{
					this->protectRelationOp(rhs);
					return this->determinant <= rhs.determinant;
				}
				bool operator>(const Literal& rhs)
				{
					this->protectRelationOp(rhs);
					return this->determinant > rhs.determinant;
				}
				bool operator>=(const Literal& rhs)
				{
					this->protectRelationOp(rhs);
					return this->determinant >= rhs.determinant;
				}

				Literal& operator+=(const Literal& rhs)
				{
					protectSizes(rhs);
					for (auto x = 0; x < this->data.size(); x++)
					{
						if(rhs.data.size() == 1)
							this->data.at(x) += rhs.data.at(0);
						else
							this->data.at(x) += rhs.data.at(x);
					}
					updateDeterminant();
					return *this;
				}
				Literal& operator-=(const Literal& rhs)
				{
					protectSizes(rhs);
					for (auto x = 0; x < this->data.size(); x++)
					{
						if (rhs.data.size() == 1)
							this->data.at(x) -= rhs.data.at(0);
						else
							this->data.at(x) -= rhs.data.at(x);
					}
					updateDeterminant();
					return *this;
				}
				Literal& operator*=(const Literal& rhs)
				{
					protectSizes(rhs);
					for (auto x = 0; x < this->data.size(); x++)
					{
						if (rhs.data.size() == 1)
							this->data.at(x) *= rhs.data.at(0);
						else
							this->data.at(x) *= rhs.data.at(x);
					}
					updateDeterminant();
					return *this;
				}
				Literal& operator/=(const Literal& rhs)
				{
					protectSizes(rhs);
					for (auto x = 0; x < this->data.size(); x++)
					{
						if (rhs.data.size() == 1)
							this->data.at(x) /= rhs.data.at(0);
						else
							this->data.at(x) /= rhs.data.at(x);
					}
					updateDeterminant();
					return *this;
				}

			private:
				void updateDeterminant() {
					if (this->data.size() == 1)
						this->determinant = data.at(0);
					else
						this->determinant = data.at(0) * data.at(3) - data.at(1) * data.at(2);
				}

				void checkSizes(const Literal& rhs)
				{
					if (this->data.size() != rhs.data.size())
					{
						std::string errMsg("Used matrices have different sizes");
						throw std::exception(errMsg.c_str());
					}
				}

				void protectSizes(const Literal& rhs)
				{
					if (this->data.size() != 4 && rhs.data.size() != 1 || this->data.size() != rhs.data.size())
					{
						std::string errMsg("Used matrices have not appropriate sizes");
						throw std::exception(errMsg.c_str());
					}
				}

				void protectRelationOp(const Literal& rhs)
				{
					if (this->getSize() != rhs.getSize())
					{
						std::string errMsg("Comparison operator makes no sense for matrices");
						throw std::exception(errMsg.c_str());
					}
				}
			};
		}
	}
}

#endif