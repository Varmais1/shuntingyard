#include <iostream>
#include <cstring>

class Node {
 public:
  Node();
  Node(char nData, Node* nLeft, Node* nRight);
  ~Node();
  char getData();
  void setData(char nData);
  void setLeft(Node* nLeft);
  void setRight(Node* nRight);
  Node* getLeft();
  Node* getRight();

 private:
  char data;
  Node* left;
  Node* right;
};
