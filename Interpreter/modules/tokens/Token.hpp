#ifndef TKOM_TOKENS_TOKEN_HPP
#define TKOM_TOKENS_TOKEN_HPP

#include <string>

#include "TokenType.hpp"

using TokenType = tkom::modules::tokens::TokenType;

namespace tkom {

	namespace modules
	{
		namespace tokens
		{
			struct Token
			{
				Token() = default;
				Token(const TokenType& type) : type(type) {}

				TokenType type = TokenType::Invalid;
				std::string value = "";

				unsigned int line = 0;
				unsigned int position = 0;
				std::streampos lineStart;
			};
		}
	}
}

#endif