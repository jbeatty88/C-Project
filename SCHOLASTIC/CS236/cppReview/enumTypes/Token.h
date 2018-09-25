#pragma once

#include <iostream>
#include <sstream>
#include <vector>

enum token {
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
  STRING,
  COMMENT,
  ID,
  UNDEFINED,
  ENDOFILE
};

class Token {
 private:
  std::string tokenString;
  int tokenLineNum;
  token tokenType;
  char tokenChar;
  std::vector<std::string> tokenStringsVec;
  
 public:
  Token(std::string val, int ln, token tt );
  Token(char val, int ln, token tt);
  ~Token();
  std::string EnumString(token tt);
  void FormatPrint();
  void FormatCharPrint();
  void PrintVec(std::vector<std::string> tokenStringsVec);
  
  
};
