#pragma once
#include <iostream>
#include <string>

// Datalog Language in a nutshell
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

class Token
{
private:
	TokenType type;
	std::string strVal;
	size_t lineNum;
	//std::vector<std::string> outputVec;
	std::string EnumString(TokenType tt) const;

public:
	Token(TokenType type = UNDEFINED, std::string val = "", size_t lineNum = 0);
	~Token();
	std::string ToString();
	TokenType GetTokenType();
	std::string GetTokenVal();
	size_t GetTokenLineNum();
	friend std::ostream &operator<< ( std::ostream &output, const Token &T) {
		output << "Token: " << T.EnumString(T.type) << " Str: " << T.strVal << " Line Number: " << T.lineNum;
		return output;
	};
};

