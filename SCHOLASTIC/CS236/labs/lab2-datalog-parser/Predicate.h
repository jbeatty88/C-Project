#pragma once                                                                                                                                                                                                      
#include <string>

/*
headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN
predicateList	->	COMMA predicate predicateList | lambda
*/

class Predicate
{                                                                                                                                                                                                  
 private:                                                                                                                                                                                                          
 public:
  std::string toString();
};
