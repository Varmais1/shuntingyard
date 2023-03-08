#include <iostream>
#include <cstring>
#include "node.h"

class Stack {
 public:
  Stack();
  ~Stack();
  Node* getTop();
  void push(Node* nTop);
  Node* pop();
  
 private:
  Node* top;
};
