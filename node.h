#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>

class Node {
 public:
  Node();
  Node(char nData);
  Node(char nData, Node* nLeft, Node* nRight, Node* nNext, Node* nPrevious);
  ~Node();
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
  int getPrecedence();
  
 private:
  char data;
  Node* left;
  Node* right;
  Node* next;
  Node* previous;
};
#endif
