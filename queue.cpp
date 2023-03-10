#include "queue.h"

using namespace std;

Queue::Queue() {
  end = NULL;
  beginning = NULL;
}

Queue::Queue(Node* nEnd, Node* nBeginning) {
  end = nEnd;
  beginning = nBeginning;
}

void Queue::enqueue(Node* nBeginning) {
  beginning->setLeft(nBeginning);
  nBeginning->setRight(beginning);
  beginning = nBeginning;
}

Node* Queue::dequeue() {
  Node* temp = end;
  end = end->getLeft();
  return temp;
}

Node* Queue::getBeginning() {
  return beginning;
}

Node* Queue::getEnd() {
  return end;
}
