#include "stack.h"
/* Name: Ishaan Varma
Date: 3/22/2023
Purpose: Implementation of the Stack Class
 */

//constructors and destructor
Stack::Stack() {
  top = NULL;
}

Stack::Stack(Node* nTop) { 
  top = nTop;
}
  
Stack::~Stack() {
  if(top!=NULL) {
    delete top;
  }
}

//push function
void Stack::push(Node* nTop) {
  //if the stack already has a data member
  if(top != NULL) {
    //set the previous data member's next to the new top
    top->setNext(nTop);
  }
  //set the previous of the new top to the old top
  nTop->setPrevious(top);
  //set top to the new top
  top = nTop;
}


//pop function
Node* Stack::pop() {
  //set the top to the previous element, and return the old top
  Node* temp = top;
  top = top->getPrevious();
  return temp;
}

//peek, returns the top element
Node* Stack::peek() {
  return top;
}
