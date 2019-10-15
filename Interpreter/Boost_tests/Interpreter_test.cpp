// Po odkomentowaniu testy zaczna dzialac ale nalezy zakomentowac plik main.cpp
// Testy uruchamiasz w eksploratorze testow
// Test lexer_tryBuildNumber_type_of_integer Przydaloby sie ograniczenie na typ int i double 

//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN
//#define BOOST_TEST_MODULE tkom_interpreter_tests
#include <boost/test/auto_unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include "../modules/lexer/Lexer.hpp"
#include "../modules/parser/Parser.hpp"
#include <fstream>  

using Lexer = tkom::modules::Lexer;
using Parser = tkom::modules::Parser;

namespace
{
	struct TestInterpreter
	{
		std::string filename;
		Token token;
		TokenType tokentype;

		TestInterpreter(): filename("Boost_tests/test.txt"){}

		void prepareStreamValue(std::string streamValue) {
			std::ofstream file(filename);
			if (file.is_open())
			{
				file << streamValue << std::endl;
				file.close();
			}
			else {
				std::cout << "Error opening file";
			}
		}
	};
}


BOOST_FIXTURE_TEST_SUITE(TestLexerFunctions, TestInterpreter)

BOOST_AUTO_TEST_CASE(lexer_constructor)
{
	prepareStreamValue("my text here!");
	Lexer lexer(filename);

	BOOST_TEST_MESSAGE("Filename: " + filename);
	BOOST_TEST_MESSAGE("Token value: " + token.value);
	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));
	BOOST_TEST_MESSAGE("Token type name: " + getTokenTypeName(token.type));

	BOOST_REQUIRE_EQUAL(token.line, 0);
	BOOST_REQUIRE_EQUAL(token.position, 0);
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Invalid");
}

BOOST_AUTO_TEST_CASE(lexer_token_line_and_position)
{
	prepareStreamValue("Line1 \n"
					   " Line2  pos \n" // gdyby nie bylo spacji po pos to powstalby identyfikator posLine4
					   "\n"
					   "Line4 end");

	Lexer lexer(filename);
	token = lexer.nextToken();

	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));

	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "Line1");
	BOOST_REQUIRE_EQUAL(token.line, 1);
	BOOST_REQUIRE_EQUAL(token.position, 0);

	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));

	token = lexer.nextToken();
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "Line2");
	BOOST_REQUIRE_EQUAL(token.line, 2);
	BOOST_REQUIRE_EQUAL(token.position, 1);

	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));

	token = lexer.nextToken();
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "pos");
	BOOST_REQUIRE_EQUAL(token.line, 2);
	BOOST_REQUIRE_EQUAL(token.position, 8);

	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));

	token = lexer.nextToken();
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "Line4");
	BOOST_REQUIRE_EQUAL(token.line, 4);
	BOOST_REQUIRE_EQUAL(token.position, 0);

	BOOST_TEST_MESSAGE("Token line: " + std::to_string(token.line));
	BOOST_TEST_MESSAGE("Token position: " + std::to_string(token.position));

	token = lexer.nextToken();
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "end");
	BOOST_REQUIRE_EQUAL(token.line, 4);
	BOOST_REQUIRE_EQUAL(token.position, 6);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "EndOfFile");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_EOF)
{
	prepareStreamValue("");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "EndOfFile");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_StringLiteral)
{
	prepareStreamValue(" \"my text here\" quoted ");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "StringLiteral");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_KeywordOrIdentifier)
{
	prepareStreamValue("function call ( ) {; }");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Function");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_NumberLiteral)
{
	prepareStreamValue(" 654 464 3.54 ");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_SpecialCharacter)
{
	prepareStreamValue("a = (4, 5) ");
	Lexer lexer(filename);
	lexer.nextToken();

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Assignment");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "ParenthOpen");
}

BOOST_AUTO_TEST_CASE(lexer_nextToken_return_Invalid_token_type)
{
	prepareStreamValue("%876 ^");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Invalid");
}

BOOST_AUTO_TEST_CASE(lexer_skipWhitespace)
{
	prepareStreamValue("	a  b"
					   "		d");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
}

BOOST_AUTO_TEST_CASE(lexer_skipCommentary_with_exception_of_unclosed_commentary)
{
	prepareStreamValue(" ala5 # commentary "
		"		is not closed ");
	Lexer lexer(filename);
	bool getException = false;

	try
	{
		lexer.nextToken();
		lexer.nextToken();
	}
	catch (const std::exception& )
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_CASE(lexer_skipCommentary_without_exception)
{
	prepareStreamValue( " # first line \n"
						" second line # Idea");
	Lexer lexer(filename);
	token = lexer.nextToken();

	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "Identifier");
	BOOST_REQUIRE_EQUAL(token.value, "Idea");
	BOOST_REQUIRE_EQUAL(token.line, 2);
}

BOOST_AUTO_TEST_CASE(lexer_tryBulidString_with_quotation_marks) 
{
	prepareStreamValue(" \" some text1 \" \n"
					   "\"some text2\" ");
	Lexer lexer(filename);
	token = lexer.nextToken();
	
	BOOST_TEST_MESSAGE("Token value: " + token.value);
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "StringLiteral");
	token = lexer.nextToken();

	BOOST_TEST_MESSAGE("Token value: " + token.value);
	BOOST_REQUIRE_EQUAL(getTokenTypeName(token.type), "StringLiteral");
}

BOOST_AUTO_TEST_CASE(lexer_tryBulidString_with_exception_of_unclosed_String) 
{
	prepareStreamValue(" pritf ( \" print text on"
					   "the screen "
					   " but without second quotation mark");
	Lexer lexer(filename);
	bool getException = false;

	try
	{
		lexer.nextToken();
		lexer.nextToken();
		lexer.nextToken();
	}
	catch (const std::exception& )
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildKeywordOrIdentifier_with_all_keywords)
{
	prepareStreamValue("if "
		"while "
		"else "
		"return "
		"continue "
		"break "
		"var "
		"printf ");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "If");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "While");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Else");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Return");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Continue");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Break");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Var");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Printf");
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildKeywordOrIdentifier_build_identifier_similar_to_keyword)
{
	prepareStreamValue("ifa "
		"whilea "
		"elseifa ");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Identifier");
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildNumber_with_a_few_zeros_at_the_beginning) 
{
	prepareStreamValue("number 0065");
	Lexer lexer(filename);
	bool getException = false;

	try
	{
		lexer.nextToken();
		lexer.nextToken();
	}
	catch (const std::exception& )
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildNumber_type_of_integer)
{
	prepareStreamValue(" 12 0 99999999999 ");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildNumber_type_of_double)
{
	prepareStreamValue(" 12.23 0.324 9.999999999 "); 
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "NumberLiteral");
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildNumber_with_exception_of_invalid_number_format)
{
	prepareStreamValue(" 902 80.40.54 ");
	Lexer lexer(filename);
	bool getException = false;

	try
	{
		lexer.nextToken();
		lexer.nextToken();
	}
	catch (const std::exception& )
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildSpecialCharacter_with_all_available_tokens)
{
	prepareStreamValue( "== "
						"= "
						"<= "
						"< "
						">= "
						"> "
						"!= "
						"! "
						"&& "
						"|| "
						"( "
						") "
						"{ "
						"} "
						", "
						"; "
						"+ "
						"- "
						"* "
						"/ "
						". "	);
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Equality");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Assignment");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "LessOrEqual");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "LessThan");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "GreaterOrEqual");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "GreaterThan");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Inequality");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Negation");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "And");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Or");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "ParenthOpen");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "ParenthClose");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "CurlyBracketOpen");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "CurlyBracketClose");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Comma");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Semicolon");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Plus");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Minus");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Multiply");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Divide");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Dot");
}

BOOST_AUTO_TEST_CASE(lexer_tryBuildSpecialCharacter_with_token_Invalid_for_Or_And_operation)
{
	prepareStreamValue("| & upsss");
	Lexer lexer(filename);

	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Invalid");
	BOOST_REQUIRE_EQUAL(getTokenTypeName(lexer.nextToken().type), "Invalid");
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE(TestParserFunctions, TestInterpreter)

BOOST_AUTO_TEST_CASE(parser_parse_without_exception)
{
	prepareStreamValue( "function main() {"
						"var a = 8;"
						"printf(a);"
						"}");
	Lexer lexer(filename);
	Parser parser(lexer);
	bool getException = false;

	try
	{
		parser.parse();
	}
	catch (const std::exception&)
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, false);
}

BOOST_AUTO_TEST_CASE(parser_parse_exception_with_wrong_token_type)
{
	prepareStreamValue( "function main() {"
						"var a = 8"
						"printf(a);"
						"}");
	Lexer lexer(filename);
	Parser parser(lexer);
	bool getException = false;

	try
	{
		parser.parse();
	}
	catch (const std::exception&)
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_CASE(parser_parse_exception_with_wrong_last_token_type)
{
	prepareStreamValue("function main() {"
		"var a = 8;"
		"printf(a);"
		"if(2 == 3) {"
		"} ");
	Lexer lexer(filename);
	Parser parser(lexer);
	bool getException = false;

	try
	{
		parser.parse();
	}
	catch (const std::exception&)
	{
		getException = true;
	}

	BOOST_REQUIRE_EQUAL(getException, true);
}

BOOST_AUTO_TEST_SUITE_END()