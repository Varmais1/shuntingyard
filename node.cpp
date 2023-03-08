#include "node.h"

Node::Node() {
  data = '0';
  left = NULL;
  right = NULL;
}

Node::Node(char nData, Node* nLeft, Node* nRight) {
  data = nData;
  left = nLeft;
  right = nRight;
}

char Node::getData() {
  return data;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

void Node::setData(char nData) {
  data = nData;
}

void Node::setLeft(Node* nLeft) {
  left = nLeft;
}

void Node::setRight(Node* nRight) {
  right = nRight;
}


Node::~Node() {
  delete left;
  delete right;
}
