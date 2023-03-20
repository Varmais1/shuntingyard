#include "tree.h"

using namespace std;

void infix(Node* top) {
  if(top != NULL) {
    if(!isdigit(top->getData())) {
      cout << "(";
    }
    infix(top->getLeft());
    cout << top->getData();
    infix(top->getRight());
    if(!isdigit(top->getData())) {
      cout << ")";
    }
  }
}

void postfix(Node* top) {
  if(top != NULL) {
    postfix(top->getLeft());
    postfix(top->getRight());
    cout << top->getData();
  }
}

void prefix(Node* top) {
  if(top!=NULL) {
    cout << top->getData();
    prefix(top->getLeft());
    prefix(top->getRight());
  }
}
