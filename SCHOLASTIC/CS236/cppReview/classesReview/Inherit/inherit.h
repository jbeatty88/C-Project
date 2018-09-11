#include <iostream>
#include <string>

class Parents {
 public:
  Parents();
  ~Parents();
  void setChildCount(int numKids);
  int getChildCount();
  void setIsMarried(bool answer);
  void getIsMarried();
  
 private:
  int childCount;
  bool isMarried;
  
      
};

class Wife: public Parents {
 private:
  std::string firstName;
  std::string maidenName;
  std::string marriedName;
  
 public:
  Wife(std::string fName, std::string mName);
  ~Wife();
  
};

class Husband: public Parents {
 private:
  std::string firstName;
  std::string lastName;
 public:
  Husband(std::string fName, std::string lName);
  ~Husband();
};
