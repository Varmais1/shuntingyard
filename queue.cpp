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
  if(beginning!=NULL) {
    beginning->setPrevious(nBeginning);
    nBeginning->setNext(beginning);
  }
  beginning = nBeginning;
}

Node* Queue::dequeue() {
  Node* temp = end;
  if(end != NULL) {
    end = end->getLeft();
  }
  return temp;
}

Node* Queue::getBeginning() {
  return beginning;
}

Node* Queue::getEnd() {
  return end;
}

Queue::~Queue() {
  delete beginning;
  delete end;
}
