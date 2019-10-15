#ifndef TKOM_TOKENS_TOKENTYPE_HPP
#define TKOM_TOKENS_TOKENTYPE_HPP

#include <unordered_map>
#include <string>

namespace tkom {

	namespace modules
	{
		namespace tokens
		{
			enum class TokenType : unsigned int
			{
				Function,
				If,
				While,
				Else,
				Return,
				Continue,
				Break,
				Var,
				Printf,

				ParenthOpen,
				ParenthClose,
				CurlyBracketOpen,
				CurlyBracketClose,
				Comma,
				Assignment,
				Semicolon,

				Negation,
				Or,
				And,
				Equality,
				Inequality,
				LessThan,
				GreaterThan,
				LessOrEqual,
				GreaterOrEqual,
				Plus,
				Minus,
				Multiply,
				Divide,

				Dot,
				Identifier,
				NumberLiteral,
				StringLiteral,

				Invalid,
				EndOfFile,
				Undefined
			};

			const std::unordered_map<unsigned int, std::string> tokenTypeNames = {
				{ 0,  "Function"},
				{ 1,  "If"},
				{ 2, "While"},
				{ 3, "Else"},
				{ 4, "Return"},
				{ 5, "Continue"},
				{ 6, "Break"},
				{ 7, "Var"},
				{ 8, "Printf"},

				{ 9,  "ParenthOpen"},
				{ 10,  "ParenthClose"},
				{ 11,  "CurlyBracketOpen"},
				{ 12,  "CurlyBracketClose"},
				{ 13,  "Comma"},
				{ 14,  "Assignment"},
				{ 15,  "Semicolon"},

				{ 16, "Negation"},
				{ 17, "Or"},
				{ 18, "And"},
				{ 19, "Equality"},
				{ 20, "Inequality"},
				{ 21, "LessThan"},
				{ 22, "GreaterThan"},
				{ 23, "LessOrEqual"},
				{ 24, "GreaterOrEqual"},
				{ 25, "Plus"},
				{ 26, "Minus"},
				{ 27, "Multiply"},
				{ 28, "Divide"},

				{ 29, "Dot"},
				{ 30, "Identifier"},
				{ 31, "NumberLiteral"},
				{ 32, "StringLiteral"},

				{ 33, "Invalid"},
				{ 34, "EndOfFile"},
				{ 35, "Undefined"}
			};

			inline const std::string getTokenTypeName(const TokenType& tokenType)
			{
				return tokenTypeNames.at(static_cast<unsigned int>(tokenType));
			};
		}
	}
}

#endif