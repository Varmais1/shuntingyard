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
  top->setNext(nTop);
  nTop->setPrevious(top);
  top = nTop;
}

Node* Stack::pop() {
  Node* temp = top;
  top = top->getPrevious();
  return temp;
}

Node* Stack::peek() {
  return top;
}
