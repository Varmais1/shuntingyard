#include "node.h"

Node::Node() {
  data = '0';
  left = NULL;
  right = NULL;
  next = NULL;
  previous = NULL;
}

Node::Node(char nData, Node* nLeft, Node* nRight, Node* nNext, Node* nPrevious) {
  data = nData;
  left = nLeft;
  right = nRight;
  next = nNext;
  previous = nPrevious;
}

Node::Node(char nData) {
  data = nData;
  left = NULL;
  right = NULL;
  next = NULL;
  previous = NULL;
}

char Node::getData() {
  return data;
ou}

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

void Node::setNext(Node* nNext) {
  next = nNext;
}

Node* Node::getNext() {
  return next;
}

void Node::setPrevious(Node* nPrevious) {
  previous = nPrevious;
}

Node* Node::getPrevious() {
  return previous;
}

int Node::getPrecedence() {
  if(data == '(') {
    return 5;
  }
  if(data == '^') {
    return 4;
  }
  else if(data == '*' || data == '/') {
    return 3;
  }
  else if(data == '+' || data == '-') {
    return 2;
  }
  return 0;
}

Node::~Node() {
  delete left;
  delete right;
  delete next;
}
