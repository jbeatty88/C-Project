#include "Person.h"
#include <iostream>

Person::Person(std::string name): personName(name) {
  std::cout << "Object is being created, named " << name << std::endl;
  
}

Person::~Person(void) {
  std::cout << "Object is being deleted. " << farewell << personName << std::endl;
}

void Person::Greet() {
  std::cout << greeting << personName <<  std::endl;
}
