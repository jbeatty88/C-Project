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
	std::string val;
	TokenType type;
	int lineNum;
	std::string enumToString(TokenType tt);

public:
	Token(TokenType type, std::string val, int lineNum);
	~Token();
	std::string toString();
};

