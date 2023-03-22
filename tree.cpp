#include "tree.h"
/* Name: Ishaan Varma
   Date: 3/22/2023
   Purpose: where tree traversal methods are implemented
 */
using namespace std;


//function for infix traversal of a binary expression tree
void infix(Node* top) {
  //if you are not at the end of the tree
  if(top != NULL) {
    //if the node isn't a number, output a right parenthesis
    if(!isdigit(top->getData())) {
      cout << "(";
    }
    //call this function for the left child
    infix(top->getLeft());
    //print out the data memeber
    cout << top->getData();
    //call this function for the right child
    infix(top->getRight());
    //if the data member is not a digit, print out a left parenthesis
    if(!isdigit(top->getData())) {
      cout << ")";
    }
  }
}


//function for postfix traversal of a binary expression tree
void postfix(Node* top) {
  //if you are not at the end of the tree
  if(top != NULL) {
    //call this function for the left child, then the right child, then print out this data member
    postfix(top->getLeft());
    postfix(top->getRight());
    cout << top->getData();
  }
}


//function for prefix traversal of a binary expression tree
void prefix(Node* top) {
  //if you are not at the end of the tree
  if(top!=NULL) {
    //print out this data member, then call this function for the left child, then the right child
    cout << top->getData();
    prefix(top->getLeft());
    prefix(top->getRight());
  }
}
