#pragma once
#include <string>

/* scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN */

class Scheme{                                                                                                                                                                                                  
 private:

 public:
  Scheme();
  ~Scheme();
  void Parse();
  std::string ToString();
};
