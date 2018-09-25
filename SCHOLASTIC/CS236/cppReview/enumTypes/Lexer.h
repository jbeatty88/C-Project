#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <ctype.h>
#include <sstream>
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
  void PrintVec(std::vector<Token> tokenVec);
  void MapVec(int vecSize, std::vector<std::string> inVec);
  //void CharCheck(int vecSize, std::vector<std::string> inVec);
  void Comma(std::vector<std::string> inVec, int x, int y);
  void Period(std::vector<std::string> inVec, int x, int y);
  void Question(std::vector<std::string> inVec, int x, int y);
  void LeftParen(std::vector<std::string> inVec, int x, int y);
  void RightParen(std::vector<std::string> inVec, int x, int y);
  void Multiply(std::vector<std::string> inVec, int x, int y);
  void Add(std::vector<std::string> inVec, int x, int y);
  
  void ColonCheck(std::vector<std::string> inVec, int x, int y);
  void SchemeCheck(std::vector<std::string> inVec, int x, int y);
  void FactCheck(std::vector<std::string> inVec, int x, int y);
  void RulesCheck(std::vector<std::string> invec, int x, int y);
  void QueriesCheck(std::vector<std::string> inVec, int x, int y);

  void StringCheck(std::vector<std::string> inVec, int x, int y);
  void CommentCheck(std::vector<std::string> inVec, int x, int y);
  void EndOfFile(int vecSize);
  //void IDCheck(std::vector<std::string> inVec, int x, int y);
};
