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
  if(end != NULL) {
    Node* temp = end;
    end = end->getPrevious();
    return temp;
  }
  return NULL;
}

Node* Queue::getBeginning() {
  return beginning;
}

Node* Queue::getEnd() {
  return end;
}

void Queue::setEnd(Node* nEnd) {
  end = nEnd;
}

void Queue::setBeginning(Node* nBeginning) {
  beginning = nBeginning;
}

Queue::~Queue() {
  delete beginning;
  delete end;
}
