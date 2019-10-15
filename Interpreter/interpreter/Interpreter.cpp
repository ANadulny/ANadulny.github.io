#include "Interpreter.hpp"

#include "../modules/lexer/Lexer.hpp"
#include "../modules/parser/Parser.hpp"
#include "../modules/semantic-check/SemanticCheck.hpp"
#include "../modules/executor/Executor.hpp"

using Interpreter = tkom::Interpreter;
using Lexer = tkom::modules::Lexer;
using Parser = tkom::modules::Parser;
using SemanticCheck = tkom::modules::SemanticCheck;
using Executor = tkom::modules::Executor;

Interpreter::Interpreter(const std::vector<std::string>& arguments)
{
	/*
	try
	{
		if (arguments.size() < 1)
		{
			//ErrorHandler::error("No input file specified");
		}

		Lexer lexer(arguments.at(0));
		Parser parser(lexer);
		SemanticCheck semCheck;
		Executor executor;

		auto syntaxTree = parser.parse();
		auto checkResult = semCheck.check(syntaxTree);

		executor.execute(checkResult);

	}
	catch (std::exception &e)
	{
		//error("Terminating...", true);
	}*/
}