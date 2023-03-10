#include "stack.h"

Stack::Stack() {
  top = NULL;
}

Stack::Stack(Node* nTop) { 
  top = nTop;
}
  
Stack::~Stack() {
  delete top;
}

void Stack::push(Node* nTop) {
  top->setRight(nTop);
  nTop->setLeft(top);
  top = nTop;
}

Node* Stack::pop() {
  Node* temp = top;
  top = top->getLeft();
  return temp;
}

Node* Stack::peek() {
  return top;
}
