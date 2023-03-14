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
