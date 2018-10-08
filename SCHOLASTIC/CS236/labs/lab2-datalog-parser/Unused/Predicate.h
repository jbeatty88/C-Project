#pragma once                                                                                                                                                                                                      
#include <string>
#include <vector>
#include "Parameter.h"

/*
headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
predicateList	->	COMMA predicate predicateList | lambda
*/

class Predicate 
{
private:
public:
  Predicate() {};
  Predicate() {std::string id};
  std::string name;
  vector<Parameter> params;
  void PushBack(Parameter param);
  std::string ToString();
  bool HasConstant();
      
};
