#include "Token.h"

Token::Token(std::string val, int ln, token tt): tokenString(val), tokenLineNum(ln), tokenType(tt)  {};

Token::Token(char val, int ln, token tt): tokenChar(val), tokenLineNum(ln), tokenType(tt) {};

Token::~Token(){ /*std::cout << "Deleting a TOKEN object" << std::endl;*/ };

std::string Token::EnumString(token tt) {
  switch(tt) {
  case COMMA:
    return "COMMA";
  case PERIOD:
    return "PERIOD";
  case Q_MARK:
    return "Q_MARk";
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
  case STRING:
    return "STRING";
  case COMMENT:
    return "COMMENT";
  case ID:
    return "ID";
  case UNDEFINED:
    return "UNDEFINED";
  case ENDOFILE:
    return "EOF";
  default:
    return "NONE";
  }
}

void Token::FormatPrint() {
  std::stringstream ss;
  ss << "(" << EnumString(tokenType) << "," << "\"" << tokenString << "\"" << "," << tokenLineNum << ")";
  //std::cout << ss.str() << std::endl;
  tokenStringsVec.push_back(ss.str());
  PrintVec(tokenStringsVec);
}

void Token::FormatCharPrint() {
  std::stringstream ss;
  ss << "(" << EnumString(tokenType) << "," << "\"" << tokenChar << "\"" << "," << tokenLineNum << ")";
  //std::cout << ss.str() << std::endl;
  tokenStringsVec.push_back(ss.str());
  PrintVec(tokenStringsVec);
}

void Token::PrintVec(std::vector<std::string> tokenStringsVec){
  for(std::vector<std::string>::iterator it = tokenStringsVec.begin(); it != tokenStringsVec.end(); ++it)
    std::cout << *it << std::endl;
}
