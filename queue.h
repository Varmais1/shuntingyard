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
 private:
  Node* end;
  Node* beginning;
};
