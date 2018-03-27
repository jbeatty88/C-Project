#include <iostream>
#include <string>

/*################################################################################*/

struct node { // The format of our struct (not yet allocated in memory)
  int age;
  std::string name;
  node *next;
};

/*################################################################################*/
  
class linkedList {
 private:
  node *head, *tail; // Pointers to the head and tail of the node struct in memory
 public:
  linkedList() {  // I think this is the constructor but I am not %100 sure
    head = NULL; // Set pointers to NULL initially 
    tail = NULL;
  }

  void appendNode(int age, std::string name);
  void displayList();
  
};
