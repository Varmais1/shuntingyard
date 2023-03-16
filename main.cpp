#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"

using namespace std;

void singlelowercase(char sentence[]);
void removeSpaces(char sentence[]);

int main() {
  char command[10];
  char expression[500];
  Node* root;
  Stack ops;
  Queue output;
  Stack tree;
  
  while(true) {
    cout << "Type in infix, prefix, or postfix, or quit." << endl;
    cin >> command;
    cin.ignore();
    if(strcmp(command,"quit") == 0) {
      break;
    }
    cout << "Type in an expression in infix notation." << endl;
    cin.get(expression, 500);
    cin.ignore();
    int itr = 0;
    while(expression[itr] != '\0') {
      Node* part = new Node(expression[itr]);
      if(isdigit(part->getData())) {
	output.enqueue(part);
	itr++;
	continue;
      }
      else if(part->getData() == '+' || part->getData() == '-' || part->getData() == '*' || part->getData() == '/' || part->getData() == '^') {
	bool carat = expression[itr] == '^';
	while(ops.peek() != NULL && ops.peek()->getData() != '(' && (part->getPrecedence() < ops.peek()->getPrecedence() || part->getPrecedence() == ops.peek()->getPrecedence() && carat == false)) {
	  output.enqueue(ops.pop());
	  ops.push(part);
	}
      }
      else if(part->getData() == '(') {
	ops.push(part);
      }
      else if(part->getData() == ')') {
	if(ops.peek() != NULL) {
	  while(ops.peek()->getData() != '(' && ops.peek() != NULL) {
	    output.enqueue(ops.pop());
	  }
	  if(ops.peek()->getData() == '(') {
	    Node* temp = ops.pop();
	    delete temp;
	  }
	}
      }
      
    }
    while(ops.peek() != NULL) {
      output.enqueue(ops.pop());
    }
    while(output.getBeginning() != NULL) {
      Node* temp = output.dequeue();
      if(isdigit(temp->getData())) {
	tree.push(temp);
	continue;
      }

      Node* right = tree.pop();
      Node* left = tree.pop();
      tree.push(temp);
      temp->setRight(right);
      temp->setLeft(left);
    }
    root = tree.pop();
    
    if(strcmp(command, "infix") == 0) {
      
      cout << endl;
    }
  }
  return 0;
}


void singlelowercase(char sentence[]) {
  //iterating variable
   int i = 0;
   //go through the char array
   while(true) {
     int charVal = (int) sentence[i];
     //if the letter is capital, make it lowercase using ASCII
     if(65<=charVal && charVal <= 90) {
       sentence[i] = (char)(charVal+32);
     }
     //if the character is the null character, 
     else if(sentence[i] == '\0') {
       break;
     }
     //increment the variable
     i++;
   }
}

void removeSpaces(char sentence[]) {
  int i = 0;
  int j = 0;
  while(true) {
    if(sentence[i] != ' ') {
      i++;
    }
    else if(sentence[i] == '\0') {
      sentence[j] == '\0';
      break;
    }
    else {
      sentence[j] = sentence[i];
    }
  }
}
