#ifndef TKOM_TOKENS_KEYWORDS_HPP
#define TKOM_TOKENS_KEYWORDS_HPP

#include <unordered_map>

#include "TokenType.hpp"

using TokenType = tkom::modules::tokens::TokenType;

namespace tkom {

	namespace modules
	{
		namespace tokens
		{
			const std::unordered_map<std::string, TokenType>& keywords = {
				{ "function", TokenType::Function },
				{ "if", TokenType::If },
				{ "while", TokenType::While },
				{ "else", TokenType::Else },
				{ "return", TokenType::Return },
				{ "continue", TokenType::Continue },
				{ "break", TokenType::Break },
				{ "var", TokenType::Var },
				{ "printf", TokenType::Printf }
			};

			const std::unordered_map<char, TokenType>& simpleSigns = {
				{ '(', TokenType::ParenthOpen },
				{ ')', TokenType::ParenthClose },
				{ '{', TokenType::CurlyBracketOpen },
				{ '}', TokenType::CurlyBracketClose },
				{ ',', TokenType::Comma },
				{ ';', TokenType::Semicolon },
				{'!', TokenType::Negation},
				{ '+', TokenType::Plus },
				{ '-', TokenType::Minus },
				{ '*', TokenType::Multiply },
				{ '/', TokenType::Divide },
				{ '.', TokenType::Dot }
			};
		}
	}
}

#endif