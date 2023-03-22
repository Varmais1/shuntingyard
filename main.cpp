#include <iostream>
#include <cstring>
#include "node.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
/*Name: Ishaan Varma
Date: 3/22/2023
Purpose: Implement shuntingyard algorithm with tree traversal in order to output expressions in infix, postfix, and prefix
 */
using namespace std;

//makes the command lowercase
void singlelowercase(char sentence[]);
//removes all spaces from a char array
void removeSpaces(char sentence[]);
//deletes a tree
void deleteTree(Node* root);

//main
int main() {
  //where the command is stored
  char command[10];
  //where the expression is stored
  char expression[500];
  //where the top of the tree is stored
  Node* root;
  //operators stack
  Stack ops;
  //output queue
  Queue output;
  //stack used to build the binary expression tree
  Stack tree;

  //runs the program
  while(true) {
    //gets which type to input
    cout << "Type in infix, prefix, postfix, or quit." << endl;
    cin >> command;
    cin.ignore();
    if(strcmp(command,"quit") == 0) {
      return 0;
    }
    //gets the expression and removes all spaces
    cout << "Type in an expression in infix notation." << endl;
    cin.get(expression, 500);
    cin.ignore();
    removeSpaces(expression);
    //shuntingyard algorithm
    int itr = 0;
    //while there are characters in the expression
    while(expression[itr] != '\0') {
      //make a new node with the character as the data point
      Node* part = new Node(expression[itr]);
      //if the data point is a digit
      if(isdigit(part->getData())) {
	//put it in the queue, and set it to the end if the output doesn't hav ean element
	output.enqueue(part);
	if(itr == 0) {
	  output.setEnd(part);
	}
	//increase the iterator, and go to the next loop
	itr++;
	continue;
      }
      //if the data is an operator
      else if(part->getData() == '+' || part->getData() == '-' || part->getData() == '*' || part->getData() == '/' || part->getData() == '^') {
	//if the stack has and element and the top of the stack is not a right parenthesis and the precedence of the operator is less than the precedence of the top while the operator is not a carat, pop the operator from the stack into the queue
	bool carat = expression[itr] == '^';
	while(ops.peek() != NULL && ops.peek()->getData() != '(' && (part->getPrecedence() < ops.peek()->getPrecedence() || part->getPrecedence() == ops.peek()->getPrecedence() && carat == false)) {
	  output.enqueue(ops.pop());
	}
	//push the operator into the operator stack
	ops.push(part);
      }
      //if the character is a right parenthesis, push it into the operator stack
      else if(part->getData() == '(') {
	ops.push(part);
      }
      //the if character is a left parenthesis
      else if(part->getData() == ')') {
	//and the operator stack isn't empty
	if(ops.peek() != NULL) {
	  //while the stack isn't empty or the top isn't a right parenthesis, pop the top fom the operators stack into the output queue
	  while(ops.peek()->getData() != '(' && ops.peek() != NULL) {
	    output.enqueue(ops.pop());
	  }
	  //if the top of the operator stack is a right parenthesis, pop it, and delete it.
	  if(ops.peek()->getData() == '(') {
	    Node* temp = ops.pop();
	    delete temp;
	  }
	}
      }
      //if the operator is the first element of the output queue, set the end to it
      if(itr == 0) {
	output.setEnd(part);
      }
      //increment the iterator
      itr++;
    }
    
    //cout << "reached." << endl;

    
    //while there are operators in the output stack, pop them into the output queue
    while(ops.peek() != NULL) {
      output.enqueue(ops.pop());
    }
    //cout << "reached 2." << endl;

    //while the output queue isn't empty
    while(output.getEnd() != NULL) {
      //dequeue from the top of the output queue
      Node* temp = output.dequeue();
      //cout << "temp: " << temp;

      //if the node's data is a digit, push it into the tree stack, and go to the next iteration
      if(isdigit(temp->getData())) {
	tree.push(temp);
	continue;
      }
      //otherwise, pop the top of the tree stack into a right node, then a left node, then push the current data member into the tree stack, then set the right of the top to the right node, and the left to the left node
      Node* right = tree.pop();
      Node* left = tree.pop();
      tree.push(temp);
      temp->setRight(right);
      temp->setLeft(left);
    }
    //the top of the tree is equal to the top of the tree stack, and removes the last element from the tree stack
    root = tree.pop();

    //if the command is infix, do the infix traversal
    if(strcmp(command, "infix") == 0) {
      infix(root);
      cout << endl;
    }
    //if the command is postfix, do the postfix traversal
    else if(strcmp(command, "postfix") ==0) {
      postfix(root);
      cout << endl;
    }
    //if the command is prefix, do the prefix traversal
    else if(strcmp(command, "prefix") == 0) {
      prefix(root);
      cout << endl;
    }
    //if the command is not valid, tell the user to give a valid command
    else {
      cout << "Please enter a valid command." << endl;
    }
    //delete the tree
    deleteTree(root);
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

//removes spaes
void removeSpaces(char sentence[]) {
  //iterator variables
  int i = 0;
  int j = 0;
  while(true) {
    //if the character is a space, increment i
    if((int)sentence[i] == 32) {
      i++;
    }
    //if the character is a null character, make the end of the array a null character at the index of j
    else if(sentence[i] == '\0') {
      sentence[j] == '\0';
      break;
    }
    //otherwise, set sentence[j] = sentence[i], and increment both i and j
    else {
      sentence[j] = sentence[i];
      i++;
      j++;
    }
  }
}

//deletes the tree
void deleteTree(Node* root) {
  //if a valid node is there
  if(root != NULL) {
    //call this function for the left child, then the right child, then delete the current element
    deleteTree(root->getLeft());
    deleteTree(root->getRight());
    delete root;
  }
}
