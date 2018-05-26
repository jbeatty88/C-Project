#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include "Token.h"
#include "InputStream.h"

class Lexer
{
private:
	std::vector<Token> tokens;
	InputStream input;
	std::string tmpStr;
	std::string defStr;
	TokenType defType;
	TokenType tmpType;

public:
	Lexer(std::string fileName);
	~Lexer();
	void tokenize();
	void readSingleChar(char c);
	void readColonDash();
	void readKeyword(char c);
	void readId(char c);
	void readString(char c);
	void readComment(char c);
	void readWhitespace(char c);
	void readNone(char c);
	void pushOn(TokenType tt, std::string v, int ln);
	void setDefTypeStr(std::string s, TokenType t);
	void printV();
	void readEndline(char c);
};
