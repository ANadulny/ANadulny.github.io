#include "Tracer.hpp"

#include <iostream>

using Tracer = tkom::modules::Tracer;

Tracer::Tracer() {}

void Tracer::increaseNestingLevel(const std::string& message)
{
	if (message.length() > 0)
		this->printMessage(message);
	
	this->nestingLevel++;
}

void Tracer::resetNestingLevel()
{
	this->nestingLevel = 0;
}

void Tracer::decreaseNestingLevel(const std::string& message)
{
	if (message.length() > 0)
		this->printMessage(message);
	
	this->nestingLevel--;
}

void Tracer::printMessage(const std::string& message)
{
	if (this->nestingLevel != 0)
		this->printNestingLevel();
	std::cout << message << std::endl;
}

void Tracer::printNestingLevel()
{
	std::cout << "|";
	for (unsigned i = 0; i < this->nestingLevel; i++)
		std::cout << "=";

	std::cout << ">";
}
