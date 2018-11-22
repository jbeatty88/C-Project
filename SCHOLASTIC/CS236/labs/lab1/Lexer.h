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
	std::string defaultStr;
	TokenType defaultType;
	TokenType tmpType;

public:
	Lexer(std::string fileName);
	~Lexer();
	//void UnderTheHood(std::string prevCode = "");
	void Automata();
	void CharMachine(char c);
	void ColonMachine();
	void KeywordMachine(char c);
	void IDMachine(char c);
	void StringMachine(char c);
	void CommentMachine(char c);
	void WhitespaceMachine(char c);
	void UndefinedMachine(char c);
	void MakeTokenVec(TokenType tt, std::string v, size_t ln);
	void SetDefaults(std::string s, TokenType t);
	void PrintVec();
	void EndLineMachine(char c);
};
