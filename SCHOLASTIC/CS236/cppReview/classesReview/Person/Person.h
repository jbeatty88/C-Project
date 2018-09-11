#include <iostream>
#include <string>

class Person {
 private:
  const std::string greeting = "Hello, ";
  const std::string farewell = "Goodbye ";
  std::string personName;

  
 public:
  Person(std::string name);
  ~Person();
  
  void Greet();
};
