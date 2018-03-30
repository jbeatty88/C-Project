/* Written by Josh Beatty */
#include <iostream>
#include <string>
#include "linkedList.h"

using namespace std;

void prompt() {
  int age     = 0;
  int numPpl  = 0;
  int pos     = 0;
  string insertStyle;
  string firstName;
  string answer;
  linkedList amigos;
  
  cout << "Let's make a list of the people in your life" << endl;
  cout << endl;
  cout << "How many people do you plan to add to this list?" << endl;
  cout << endl;
  cin  >> numPpl;
  
  for(int i = numPpl; i > 0; i--) {
    cout << "First  name?" << endl;
    cin  >> firstName;
    cout << "Age?" << endl;
    cin  >> age;
    amigos.appendNode(age, firstName);
  };

  cout << "Do you want to display your list or add more?" << endl;
  cin  >> answer;
  if(answer == "yes") {
    amigos.displayList();
  }
  else if(answer == "add"){
    cout << "First name?" << endl;
    cin  >> firstName;
    cout << "Age?" << endl;
    cin  >> age;
    cout << "How would you like to inset?" << endl;
    cin >> insertStyle;
    
    if (insertStyle == "prepend" ) {
      amigos.prePend(age, firstName);
    }
    else if (insertStyle == "insert") {
      cout  << "Where would you like to insert it?" << endl;
      cin   >> pos;
      amigos.positionInsert(pos, age, firstName);
    }
  }
  
  else{
    cout << "Bye bye" << endl;
  }
   amigos.displayList();
}

int main() {
  
  prompt();
  
  
  return 0;
}
