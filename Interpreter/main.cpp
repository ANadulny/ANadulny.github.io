#include <iostream>
#include "modules/lexer/Lexer.hpp"
#include "modules/parser/Parser.hpp"
#include "modules/semantic-check/SemanticCheck.hpp"
#include "modules/executor/Executor.hpp"

using Lexer = tkom::modules::Lexer;
using Parser = tkom::modules::Parser;
using SemanticCheck = tkom::modules::SemanticCheck;
using Executor = tkom::modules::Executor;

int main(int argc, char** argv)
{
	/*
	std::string file = "tests/test_lexer.txt";
	//std::string file = "Boost_tests/test.txt";
	//std::string file = "tests/test_commentary.txt";

	Lexer lexerTest(file);
	Token token;
	int i = 0;

	std::cout << "Lexer test" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;

	try {
		do {
			token = lexerTest.nextToken();
			TokenType tokentype = token.type;

			std::cout << "Token number [" << i++ << "]" << std::endl;
			std::cout << "Token line " << token.line;
			std::cout << ", position " << token.position;
			std::cout << ", value " << token.value;
			std::cout << ", type " << getTokenTypeName(tokentype) << std::endl;

		} while (token.type != TokenType::EndOfFile && token.type != TokenType::Invalid);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Parser test" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;

	file = "tests/test_parser.txt";
	Lexer lexer(file);
	Parser parser(lexer);
	try {
		parser.parse();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	*/


	/*

	std::string file1 = "tests/test_semantic_check.txt";
	Lexer lexerTest(file1);
	Token token;
	int i = 0;

	std::cout << "Lexer test" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl;

	try {
		do {
			token = lexerTest.nextToken();
			TokenType tokentype = token.type;

			std::cout << "Token number [" << i++ << "]" << std::endl;
			std::cout << "Token line " << token.line;
			std::cout << ", position " << token.position;
			std::cout << ", value " << token.value;
			std::cout << ", type " << getTokenTypeName(tokentype) << std::endl;

		} while (token.type != TokenType::EndOfFile && token.type != TokenType::Invalid);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "--------------------------------------------" << std::endl;
	

	*/


	std::string file = "tests/test_semantic_check.txt";
	Lexer lexer(file);
	Parser parser(lexer);
	try
	{
		SemanticCheck semCheck;
		Executor executor;

		auto syntaxTree = parser.parse();
		std::cout << std::endl;
		std::cout << "Semantic check:" << std::endl;
		std::cout << std::endl;
		auto checkResult = semCheck.check(syntaxTree);

		std::cout << std::endl;
		std::cout << "Executor" << std::endl;
		std::cout << std::endl;
		executor.execute(checkResult);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	system("PAUSE");
	return 0;
}
