#include "Lexer.hpp"
#include "../tokens/Keywords.hpp"
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <iostream>

using Lexer = tkom::modules::Lexer;

Lexer::Lexer(const std::string& fileName) : reader(fileName) {
	getSign();
};

const Token Lexer::nextToken() {
	Token token;

	while (this->skipWhitespace() || this->skipCommentary());

	token.line = this->reader.getCurrentLineNo();
	token.position = this->reader.getCurrentSignPosition() - 1;

	if (this->reader.hasFinished()) {
		token.type = TokenType::EndOfFile;
		return token;
	}

	if (this->tryBuildString(token)) {
		return token;
	}

	if (this->tryBuildKeywordOrIdentifier(token)) {
		return token;
	}

	if (this->tryBuildNumber(token)) {
		return token;
	}

	if (this->tryBuildSpecialCharacter(token)) {
		return token;
	}

	token.type = TokenType::Invalid;
	return token;
}

void Lexer::getSign()
{
	this->actualSign = this->reader.nextSign();
}

const bool Lexer::skipWhitespace()
{
	if (isspace(actualSign)) {
		getSign();
		return true;
	}
	return false;
}

const bool Lexer::skipCommentary()
{
	if (actualSign == '#') {
		do {
			getSign();
			if (this->reader.hasFinished()) {
				std::string errorMsg("Invalid operation: commentary was not closed!\n");
				throw std::exception(errorMsg.c_str());
				return false; // invalid operation
			}
		} while (actualSign != '#');

		getSign();
		return true;
	}
	return false;
}

const bool Lexer::tryBuildString(Token& token)
{
	if (actualSign == '"') {
		std::string stringBuffer;
		getSign();
		while (actualSign != '"') {
			if (actualSign == '\\') {
				getSign();
				if (actualSign == '\"') {
					stringBuffer.push_back(actualSign);
				}
				else {
					stringBuffer.push_back('\\');
				}
			}
			else {
				stringBuffer.push_back(actualSign);
			}
			getSign();

			if (this->reader.hasFinished()) {
				std::string errorMsg("Invalid operation: string was not closed with \" !\n");
				throw std::exception(errorMsg.c_str());
				break;
			}
		}

		getSign();
		token.type = TokenType::StringLiteral;
		token.value = stringBuffer;

		return true;
	}
	return false;
}

const bool Lexer::tryBuildKeywordOrIdentifier(Token& token)
{
	if (isalpha(actualSign)) {
		std::string stringBuffer;
		do {
			stringBuffer.push_back(actualSign);
			getSign();
		} while (isalnum(actualSign) || actualSign == '_');

		auto tmp = stringBuffer;
		std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

		if (tokens::keywords.count(tmp) == 1) {
			token.type = tokens::keywords.at(tmp);
		}
		else {
			token.type = TokenType::Identifier;
			token.value = stringBuffer;
		}
		return true;
	}
	return false;
}

const bool Lexer::tryBuildNumber(Token & token)
{
	if (isdigit(actualSign)) {
		std::string numberBuffer;
		bool invalidNumber = false;

		if (actualSign == '0') {
			numberBuffer.push_back(actualSign);
			getSign();
			if (isdigit(actualSign))
				invalidNumber = true;
		}

		while (isdigit(actualSign)) {
			numberBuffer.push_back(actualSign);
			getSign();
		}

		if (actualSign == '.') {
			numberBuffer.push_back(actualSign);
			getSign();
			if (!isdigit(actualSign)) {
				invalidNumber = true;
			}
			while (isdigit(actualSign)) {
				numberBuffer.push_back(actualSign);
				getSign();
			}
		}

		if (actualSign == '.' || invalidNumber) {
			std::string errorMsg("Invalid number: wrong number format!\n");
			throw std::exception(errorMsg.c_str());
		}

		token.value = numberBuffer;
		token.type = TokenType::NumberLiteral;
		return true;
	}
	return false;
}

const bool Lexer::tryBuildSpecialCharacter(Token& token)
{
	switch (actualSign) {
	case '=': {
		getSign();
		if (actualSign == '=') {
			token.type = TokenType::Equality;
			getSign();
		}
		else {
			token.type = TokenType::Assignment;
		}
		break;
	}
	case '<': {
		getSign();
		if (actualSign == '=') {
			token.type = TokenType::LessOrEqual;
			getSign();
		}
		else {
			token.type = TokenType::LessThan;
		}
		break;
	}
	case '>': {
		getSign();
		if (actualSign == '=') {
			token.type = TokenType::GreaterOrEqual;
			getSign();
		}
		else {
			token.type = TokenType::GreaterThan;
		}
		break;
	}
	case '!': {
		getSign();
		if (actualSign == '=') {
			token.type = TokenType::Inequality;
			getSign();
		}
		else {
			token.type = TokenType::Negation;
		}
		break;
	}
	case '&': {
		getSign();
		if (actualSign == '&') {
			token.type = TokenType::And;
			getSign();
		}
		else {
			token.type = TokenType::Invalid;
		}
		break;
	}
	case '|': {
		getSign();
		if (actualSign == '|') {
			token.type = TokenType::Or;
			getSign();
		}
		else {
			token.type = TokenType::Invalid;
		}
		break;
	}
	default: {
		if (tkom::modules::tokens::simpleSigns.count(actualSign) == 1) {
			token.type = tkom::modules::tokens::simpleSigns.at(actualSign);
			getSign();
		}
		else {
			return false;
		}
	}
	}
	return true;
}