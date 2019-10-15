#ifndef TKOM_MODULES_LEXER_HPP
#define TKOM_MODULES_LEXER_HPP

#include "../file-reader/FileReader.hpp"
#include "../tokens/Token.hpp"

using Token = tkom::modules::tokens::Token;
using FileReader = tkom::modules::FileReader;

namespace tkom {
	namespace modules
	{
		class Lexer
		{
		public:
			Lexer(const std::string& file);
			const Token nextToken();

		private:
			FileReader reader;
			char actualSign;

			void getSign();
			const bool skipWhitespace();
			const bool skipCommentary();
			const bool tryBuildString(Token& token);
			const bool tryBuildKeywordOrIdentifier(Token& token);
			const bool tryBuildNumber(Token& token);
			const bool tryBuildSpecialCharacter(Token& token);
		};
	}
}

#endif