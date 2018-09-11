#include <iostream>
#include "inherit.h"

using namespace std;

Parents::Parents(){
  cout << "Object being created" << endl;
}

Parents::~Parents(){
  cout << "Object being destroyed" << endl;
}

void Parents::setChildCount(int numKids) {
  cout << "...Setting Child Count..." << endl;
  childCount = numKids;
}

int Parents::getChildCount(){
  return childCount;
}

void Parents::setIsMarried(bool answer) {
  cout << "... Setting isMarried ..." << endl;
  isMarried = answer;
}

void Parents::getIsMarried() {
  cout << "... Getting isMarried() ... " << endl;
  if(isMarried == 1)
    cout << "This person is married!" << endl;
  else
    cout << "This person is not married!" << endl;
}

Wife::Wife(string fName, string mName): firstName(fName), marriedName(mName) {
  cout << "Creating a WIFE object derived from PARENTS" << endl;
  cout << "NAME: " << firstName << " " << marriedName << endl;
}
Wife::~Wife() {
  cout << "Destroying the WIFE object" << endl;
}
Husband::Husband(string fName, string lName): firstName(fName), lastName(lName) {
  cout << "Creating a HUSBAND object derived from PARENTS!" << endl;
  cout << "NAME: " << firstName << " " << lastName << endl;
}
Husband::~Husband() {
  cout << "Destroying the HUSBAND object" << endl;
}
