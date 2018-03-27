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
  cout << endl;
  cout << "How many people do you plan to add to this list?" << endl;
  cout << endl;
  cin >> numPpl;
  
  for(int i = numPpl; i > 0; i--) {
    cout << "First  name?" << endl;
    cin >> firstName;
    cout << "Age?" << endl;
    cin >> age;
    amigos.appendNode(age, firstName);
  };

  cout << "Do you want to display your list or add more?" << endl;
  cin >> answer;
  if(answer == "yes") {
    amigos.displayList();
  }
  else if(answer == "add"){
    cout << "First name?" << endl;
    cin >> firstName;
    cout << "Age?" << endl;
    cin >> age;
    amigos.prePend(age,firstName);
    amigos.displayList();
  }
  else{
    cout << "Bye bye" << endl;
  }
}

int main() {
  
  prompt();
  
  
  return 0;
}
