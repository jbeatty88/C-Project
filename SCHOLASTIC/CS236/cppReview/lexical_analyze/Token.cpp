#include "Token.h"

Token::Token(TokenType t, std::string v, size_t ln) : type(t), strVal(v), lineNum(ln) {
	MakeOutputVector();
}

Token::Token(TokenType t, char c, size_t ln) : type(t), charVal(c), lineNum(ln) {
	
	MakeOutputVector();
}

Token::~Token() {}

std::string Token::EnumString(TokenType t) {
	switch(t) {
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
		return " ";
	case UNDEFINED:
		return "UNDEFINED";
	case ENDOFILE:
		return "EOF";
	default:
		break;
	}
	return 0;
}

std::vector<std::string> Token::MakeOutputVector() {
	std::stringstream ss;
	ss << "(" << EnumString(type) << ",\"" << strVal << "\"," << lineNum << ")";
	outputVec.push_back(ss.str());
	PrintVector();
	return outputVec;
}

void Token::PrintVector() {
	std::vector<std::string>::iterator itr;
	for(itr = outputVec.begin(); itr != outputVec.end(); ++itr)
		std::cout << ' ' << *itr << std::endl;
}

size_t Token::GetVecSize() { return outputVec.size(); }