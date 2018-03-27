#include "linkedList.h"

void linkedList::appendNode(int age, std::string name) {
  node *temp = new node; // Allocate space on the stack for a node struct (UNLINKED)
  temp -> age  = age; // Set the 'age' variable in the unlinked node to input age
  temp -> name = name; // Set the 'name' var in the unlinked node to input name
  temp -> next = NULL; // Set 'next' var as NULL because it is still unlinked
  
  if(linkedList::head == NULL) { // If the linked list is empty, start a new list
    linkedList::head = temp; // Point the head to the new node in memory
    linkedList::tail = temp; // Point the tail to the new node in memory
    temp = NULL; // We don't need to point to the new node anymore because head/tail are pointing
  }
  else { // If the linked list is not empty, add to end of list
    linkedList::tail -> next = temp; // Point the last node to the new node
    linkedList::tail         = temp; // Point 'tail' to the new node

  }
}

void linkedList::displayList() {
  node *temp = new node; // Create a new pointer of type *node ptr
  temp = head; // Point the node ptr to the head of the linked list
  
  while (temp != NULL) { // While there is still a node to traverse, continue
    std::cout << temp -> name << " - "; // Display date in node
    std::cout << temp -> age << std::endl;
    temp = temp -> next; // Point to the next node in the linked list
  }
}
