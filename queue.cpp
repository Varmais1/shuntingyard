#include "queue.h"
/*Name: Ishaan Varma
Date: 3/22/2023
Purpose: where the queue class is implemented
 */
using namespace std;

//constructors
Queue::Queue() {
  end = NULL;
  beginning = NULL;
}

Queue::Queue(Node* nEnd, Node* nBeginning) {
  end = nEnd;
  beginning = nBeginning;
}

//enqueue
void Queue::enqueue(Node* nBeginning) {
  //if there is an element in the queue
  if(beginning!=NULL) {
    //set the previous of the old beginning to the new beginning and set the next of the new beginning to the old beginning
    beginning->setPrevious(nBeginning);
    nBeginning->setNext(beginning);
  }
  //make beginning the new beginning
  beginning = nBeginning;
}

//dequeue
Node* Queue::dequeue() {
  //if there is an element in the queue
  if(end != NULL) {
    //make the end the second to last node, and return the old end
    Node* temp = end;
    end = end->getPrevious();
    return temp;
  }
  return NULL;
}

//getters and setters
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

//destructor
Queue::~Queue() {
  if(beginning != NULL) {
    delete beginning;
  }
  if(end != NULL) {
    delete end;
  }
}
