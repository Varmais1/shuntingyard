#include "node.h"
#include <cstring>
#include <iostream>
/* Name: Ishaan Varma
Date: 3/22/2023
Purpose: header file for the Queue class
 */
class Queue {
 public:
  //constructors and destructors
  Queue();
  Queue(Node* nEnd, Node* nBegin);
  ~Queue();
  //adds a new node to the beginning of the queue
  void enqueue(Node* nBeginning);
  //gets rid of the last node of the queue
  Node* dequeue();
  //getters and setters
  Node* getBeginning();
  Node* getEnd();
  void setEnd(Node* nEnd);
  void setBeginning(Node* nBeginning);
 private:
  //beginning and end of the queue
  Node* end;
  Node* beginning;
};
