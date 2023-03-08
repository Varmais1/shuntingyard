#include "stack.h"

Stack::Stack() {
  top = NULL;
}

Stack::~Stack() {
  delete top;
}

Node* Stack::getTop() {
  return top;
}

void Stack::push(Node* nTop) {
  top->setRight(nTop);
  nTop->setLeft(top);
  top = nTop;
}

Node* Stack::pop() {
  Node* temp = top;
  
}
