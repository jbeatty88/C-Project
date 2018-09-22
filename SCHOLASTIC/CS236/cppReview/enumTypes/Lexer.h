#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <ctype.h>
#include "Token.h"

class Lexer {
 private:
  //typedef std::map<std::string, std::map<std::string, int>> mapType;
  //mapType tokenMap;
  //std::map<std::string, std::map<std::string, int>> tokenMap;
  std::vector<Token> tokenVec;
  
 public:
  Lexer();
  ~Lexer();
  void PrintVec(std::vector<std::string> inVec);
  void MapVec(int vecSize, std::vector<std::string> inVec);
  
};
