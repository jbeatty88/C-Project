#pragma once

#include <iostream>
#include <sstream>

enum token {
  COMMA,
  PERIOD,
  Q_MARK,
  LEFT_PAREN,
  RIGHT_PAREN,
  COLON
};

class Token {
 private:
  std::string tokenString;
  int tokenLineNum;
  token tokenType;
  char tokenChar;
  
 public:
  Token(std::string val, int ln, token tt );
  Token(char val, int ln, token tt);
  ~Token();
  std::string EnumString(token tt);
  void FormatPrint();
  void FormatCharPrint();
  
  
};
