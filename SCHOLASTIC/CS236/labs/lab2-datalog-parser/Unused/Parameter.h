#pragma once                                                                                                                                                                                                      
#include <string>

/* 
parameter	->	STRING | ID | expression 
parameterList	-> 	COMMA parameter parameterList | lambda
*/

class Parameter
{                                                                                                                                                                                                  
private:                                                                                                                                                                                                          
public:
  std::string name, val;
  Parameter() {};
  Parameter(std::string name, std::string val);
  ~Parameter() {};

  std::string GetParam();

  bool IsConstant();
};   
