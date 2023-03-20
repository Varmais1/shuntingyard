#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

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
    cout << "Type in infix, prefix, postfix, or quit." << endl;
    cin >> command;
    cin.ignore();
    if(strcmp(command,"quit") == 0) {
      return 0;
    }
    cout << "Type in an expression in infix notation." << endl;
    cin.get(expression, 500);
    cin.ignore();
    removeSpaces(expression);
    int itr = 0;
    while(expression[itr] != '\0') {
      Node* part = new Node(expression[itr]);
      if(isdigit(part->getData())) {
	output.enqueue(part);
	if(itr == 0) {
	  output.setEnd(part);
	}
	itr++;
	continue;
      }
      else if(part->getData() == '+' || part->getData() == '-' || part->getData() == '*' || part->getData() == '/' || part->getData() == '^') {
	bool carat = expression[itr] == '^';
	while(ops.peek() != NULL && ops.peek()->getData() != '(' && (part->getPrecedence() < ops.peek()->getPrecedence() || part->getPrecedence() == ops.peek()->getPrecedence() && carat == false)) {
	  output.enqueue(ops.pop());
	  ops.push(part);
	}
	if(ops.peek() == NULL) {
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
      if(itr == 0) {
	output.setEnd(part);
      }
      itr++;
    }
    cout << "reached." << endl;
    while(ops.peek() != NULL) {
      output.enqueue(ops.pop());
    }
    //cout << "reached 2." << endl;
    while(output.getEnd() != NULL) {
      Node* temp = output.dequeue();
      //cout << "temp: " << temp;
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
      infix(root);
      cout << endl;
    }
    else if(strcmp(command, "postfix") ==0) {
      postfix(root);
      cout << endl;
    }
    else if(strcmp(command, "prefix") == 0) {
      prefix(root);
      cout << endl;
    }
    else {
      cout << "Please enter a valid command." << endl;
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
    if((int)sentence[i] == 32) {
      i++;
    }
    else if(sentence[i] == '\0') {
      sentence[j] == '\0';
      break;
    }
    else {
      sentence[j] = sentence[i];
      i++;
      j++;
    }
  }
}
