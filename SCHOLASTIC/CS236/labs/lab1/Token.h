#pragma once
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
	std::string EnumString(TokenType tt);

public:
	Token(TokenType type, std::string val, size_t lineNum);
	~Token();
	std::string ToString();
};

