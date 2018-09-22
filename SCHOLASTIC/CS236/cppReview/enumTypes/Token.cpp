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
  default:
    return "NONE";
  }
}

void Token::FormatPrint() {
  std::stringstream ss;
  ss << "(" << EnumString(tokenType) << "," << "\"" << tokenString << "\"" << "," << tokenLineNum << ")";
  std::cout << ss.str() << std::endl;
  std::cout << std::endl;
}

void Token::FormatCharPrint() {
  std::stringstream ss;
  ss << "(" << EnumString(tokenType) << "," << "\"" << tokenChar << "\"" << "," << tokenLineNum << ")";
  std::cout << ss.str() << std::endl;
  std::cout << "\n";
}

