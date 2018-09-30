#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum TokenType {
	COMMA,
	PERIOD,
	Q_MARK,
	LEFT_PAREN,
	RIGHT_PAREN,
	COLON,
	COLON_DASH,
	MULTIPLY,
	ADD,
	SCHEMES,
	FACTS,
	RULES,
	QUERIES,
	ID,
	STRING,
	COMMENT,
	WHITESPACE,
	UNDEFINED,
	ENDOFILE
};

class Token {
	private:
		char charVal;
		size_t lineNum;
		std::string strVal;
		std::vector<std::string> outputVec;
		TokenType type;
	public:
		Token(TokenType t, std::string v,size_t ln);
		Token(TokenType t, char c,size_t ln);
		~Token();
		std::string EnumString(TokenType t);
		std::vector<std::string> MakeOutputVector();
		void PrintVector();	
		size_t GetVecSize();
};