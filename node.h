#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
/* Name: Ishaan Varma
   Date: 3/22/2023
   Purpose: Header of the Node Class
 */

//node class
class Node {
 public:
  //constructors
  Node();
  Node(char nData);
  Node(char nData, Node* nLeft, Node* nRight, Node* nNext, Node* nPrevious);
  //~Node()
  //getters and setters
  char getData();
  void setData(char nData);
  void setLeft(Node* nLeft);
  void setRight(Node* nRight);
  Node* getLeft();
  Node* getRight();
  void setNext(Node* nNext);
  Node* getNext();
  void setPrevious(Node* nPrevious);
  Node* getPrevious();
  //gives the precedence of an operator
  int getPrecedence();
  
 private:
  char data;
  Node* left;
  Node* right;
  Node* next;
  Node* previous;
};
#endif
