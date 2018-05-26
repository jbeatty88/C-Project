#include "Token.h"

using namespace std;

// This is where we get our tokentype for the output
std::string Token::enumToString(TokenType tt)
{
	switch (tt) {
	case COMMA:
		return "COMMA";
	case PERIOD:
		return "PERIOD";
	case Q_MARK:
		return "Q_MARK";
	case LEFT_PAREN:
		return "LEFT_PAREN";
	case RIGHT_PAREN:
		return "RIGHT_PAREN";
	case COLON:
		return "COLON";
	case COLON_DASH:
		return "COLON_DASH";
	case MULTIPLY:
		return "MULTIPLY";
	case ADD:
		return "ADD";
	case SCHEMES:
		return "SCHEMES";
	case FACTS:
		return "FACTS";
	case RULES:
		return "RULES";
	case QUERIES:
		return "QUERIES";
	case ID:
		return "ID";
	case STRING:
		return "STRING";
	case COMMENT:
		return "COMMENT";
	case WHITESPACE:
		return "WHITESPACE";
	case UNDEFINED:
		return "UNDEFINED";
	case ENDOFILE:
		return "EOF";
	default:
		return "NONE";
	}
}


Token::Token(TokenType type, string val, int lineNum)
{
	this->type = type;
	this->val = val;
	this->lineNum = lineNum;
}


Token::~Token(){}

// We take the tokentype, value from input, and line number and output it
std::string Token::toString()
{
	return "(" + enumToString(type) + ",\"" + val + "\"," + to_string(lineNum) + ")";
}
