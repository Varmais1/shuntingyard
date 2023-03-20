#include "node.h"
#include <cstring>
#include <iostream>

class Queue {
 public:
  Queue();
  Queue(Node* nEnd, Node* nBegin);
  ~Queue();
  void enqueue(Node* nBeginning);
  Node* dequeue();
  Node* getBeginning();
  Node* getEnd();
  void setEnd(Node* nEnd);
  void setBeginning(Node* nBeginning);
 private:
  Node* end;
  Node* beginning;
};
