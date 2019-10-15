#include "StdLib.hpp"

#include <iostream>
#include <limits>

using StdLib = tkom::modules::StdLib;


bool StdLib::hasFunction(const std::string& name)
{
	return (StdLib::getStandardFunctions()).count(name) == 1;
}

const std::unordered_map<std::string, std::pair<unsigned int, StdLib::StdFun>>& StdLib::getStandardFunctions()
{
	
	static const std::unordered_map<std::string, std::pair<unsigned int, StdLib::StdFun>> list = {
		{ "generate", { 4, StdLib::StdFun(&StdLib::funGenerate) } },
		{ "print", { 1, StdLib::StdFun(&StdLib::funPrint) } }//,
		//{ "determinant", { 1, StdLib::StdFun(&StdLib::funDeterminant) } }, // do zmodyfikowania z 1 na 0
		//{ "clone", { 1, StdLib::StdFun(&StdLib::funClone) } },
		//{ "getValue", { 2, StdLib::StdFun(&StdLib::funGetValue) } }, 
		//{ "setValue", { 3, StdLib::StdFun(&StdLib::funSetValue) } } 
	};
	
	return list;
}

bool StdLib::hasObjectFunction(const std::string& name)
{
	return (StdLib::getObjectFunctions()).count(name) == 1;
}

const std::unordered_map<std::string, std::pair<unsigned int, StdLib::StdFun>>& StdLib::getObjectFunctions()
{

	static const std::unordered_map<std::string, std::pair<unsigned int, StdLib::StdFun>> list = {
		{ "determinant", { 0, StdLib::StdFun(&StdLib::funDeterminant) } },
		{ "clone", { 1, StdLib::StdFun(&StdLib::funClone) } },
		{ "getValue", { 2, StdLib::StdFun(&StdLib::funGetValue) } },
		{ "setValue", { 3, StdLib::StdFun(&StdLib::funSetValue) } }
	};

	return list;
}

const StdLib::StdFun& StdLib::getStandardFunction(const std::string& name)
{
	return (StdLib::getStandardFunctions()).at(name).second;
}

unsigned int StdLib::getFunctionParamsCount(const std::string& name)
{
	return (StdLib::getStandardFunctions()).at(name).first;
}

std::shared_ptr<Literal> StdLib::callFunction(const std::string& name, ArgVec& arguments)
{
	return ((StdLib::getStandardFunction(name))(arguments));
}

const StdLib::StdFun& StdLib::getObjectFunction(const std::string& name)
{
	return (StdLib::getObjectFunctions()).at(name).second;
}

unsigned int StdLib::getObjectFunctionParamsCount(const std::string& name)
{
	return (StdLib::getObjectFunctions()).at(name).first;
}

std::shared_ptr<Literal> StdLib::callObjectFunction(const std::string& name, ArgVec& arguments)
{
	return ((StdLib::getObjectFunction(name))(arguments));
}

std::shared_ptr<Literal> StdLib::funGenerate(ArgVec& arguments)
{
	std::cout << "Generate function: "<<std::endl;
	if (arguments.at(0)->getSize() != 1 || arguments.at(1)->getSize() != 1 || arguments.at(2)->getSize() != 1 || arguments.at(3)->getSize() != 1)
	{
		std::string errorMsg("Generate function can not have arguments above one dimension");
		throw std::exception(errorMsg.c_str());
	}

	auto result = std::make_shared<Literal>();
	result->data.clear();
	for (auto& it : arguments)
	{
		std::cout << it->data.at(0) << std::endl;
		result->data.push_back(it->data.at(0));
	}
	result->setDeterminant();
	return result;
}

//Nie dziala do konca dobrze
std::shared_ptr<Literal> StdLib::funClone(ArgVec& arguments)
{
	std::cout << "Clone function: " << std::endl;
	if (arguments.at(0)->getSize() != 4)
	{
		std::string errorMsg("Clone function can not have arguments different than four dimension");
		throw std::exception(errorMsg.c_str());
	}	
	auto size = arguments.at(0)->getSize();

	arguments.at(1)->data.clear();
	arguments.at(1)->data = arguments.at(0)->data;
	arguments.at(1)->determinant = arguments.at(0)->determinant;
	return arguments.at(1);
}

std::shared_ptr<Literal> StdLib::funPrint(ArgVec& arguments)
{
	std::cout << "Print function: ";
	for (auto& it : arguments.at(0)->data)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;

	auto result = std::make_shared<Literal>();
	result->data = { 1 };
	return result;
}

std::shared_ptr<Literal> StdLib::funDeterminant(ArgVec& arguments)
{
	std::cout << "Determinant function: " << std::endl;

	auto result = std::make_shared<Literal>();
	result->data.clear();
	result->data.push_back(arguments.at(0)->determinant);
	result->determinant = arguments.at(0)->determinant;
	return result;
}

std::shared_ptr<Literal> StdLib::funGetValue(ArgVec& arguments)
{
	std::cout << "Get value function: " << std::endl;
	if (arguments.at(0)->getSize() != 1 || arguments.at(1)->getSize() != 1)
	{
		std::string errorMsg("Get value function can not have arguments above one dimension");
		throw std::exception(errorMsg.c_str());
	}

	if (arguments.at(0)->data.at(0) != 0.0 && arguments.at(0)->data.at(0) != 1.0 || arguments.at(1)->data.at(0) != 0.0 && arguments.at(1)->data.at(0) != 1.0)
	{
		std::string errorMsg("Get value function can not have value of arguments different than 0 or 1");
		throw std::exception(errorMsg.c_str());
	}

	auto result = std::make_shared<Literal>();
	result->data.clear();

	int position = arguments.at(0)->data.at(0) * 2 + arguments.at(1)->data.at(0);
	if (position != 0 && arguments.at(2)->getSize() != 4)
	{
		std::string errorMsg("Get value function variable matrix is 1 dimension so can not get value from position: " + position);
		throw std::exception(errorMsg.c_str());
	}

	result->data.push_back(arguments.at(2)->data.at(position));
	result->determinant = arguments.at(2)->data.at(position);
	return result;
}

std::shared_ptr<Literal> StdLib::funSetValue(ArgVec& arguments)
{
	std::cout << "Set value function: " << std::endl;
	if (arguments.at(0)->getSize() != 1 || arguments.at(1)->getSize() != 1 || arguments.at(2)->getSize() != 1)
	{
		std::string errorMsg("Set value function can not have arguments above one dimension");
		throw std::exception(errorMsg.c_str());
	}

	if (arguments.at(0)->data.at(0) != 0.0 && arguments.at(0)->data.at(0) != 1.0 || arguments.at(1)->data.at(0) != 0.0 && arguments.at(1)->data.at(0) != 1.0)
	{
		std::string errorMsg("Set value function can not have value of arguments different than 0 or 1");
		throw std::exception(errorMsg.c_str());
	}

	int position = arguments.at(0)->data.at(0) * 2 + arguments.at(1)->data.at(0);
	if (position != 0 && arguments.at(3)->getSize() != 4)
	{
		std::string errorMsg("Get value function variable matrix is 1 dimension so can not get value from position: " + position);
		throw std::exception(errorMsg.c_str());
	}

	arguments.at(3)->data.at(position) = arguments.at(2)->data.at(0);
	arguments.at(3)->setDeterminant();
	return arguments.at(3);
}