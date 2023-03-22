#include <iostream>
#include <cstring>
#include "node.h"
/* Name: Ishaan Varma
Date: 3/22/2023
Purpose: Header file for the Stack Class
 */

//stack class
class Stack {
 public:
  //constructors and destructors
  Stack();
  Stack(Node* nTop);
  ~Stack();
  //puts an element onto the top of the stack
  void push(Node* nTop);
  //takes an element off a stack
  Node* pop();
  //gets the top element
  Node* peek();
 private:
  //where the top element is
  Node* top;
};
