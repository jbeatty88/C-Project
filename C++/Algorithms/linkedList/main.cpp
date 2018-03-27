#include <iostream>
#include <string>
#include "linkedList.h"

using namespace std;

void prompt() {
  int age;
  int numPpl;
  string firstName;
  string answer;
  linkedList amigos;
  
  cout << "Let's make a list of the people in your life" << endl;
  cout << "How many people do you plan to add to this list?" << endl;
  cin >> numPpl;
  for(int i = numPpl; i > 0; i--) {
    cout << "What's their name?" << endl;
    cin >> firstName;
    cout << "What's their age?" << endl;
    cin >> age;
    amigos.appendNode(age, firstName);
  };

  cout << "Do you want to display your list?" << endl;
  cin >> answer;
  if(answer == "yes") {
    amigos.displayList();
  }
  else {
    
  }
}

int main() {
  
  prompt();
  
  
  return 0;
}
