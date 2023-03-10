#include <iostream>
#include <cstring>
#include "node.h"

class Stack {
 public:
  Stack();
  Stack(Node* nTop);
  ~Stack();
  void push(Node* nTop);
  Node* pop();
  Node* peek();
 private:
  Node* top;
};
