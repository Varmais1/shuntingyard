#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void singlelowercase(char sentence[]);


int main() {
  char command[10];
  
  while(true) {
    break;
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
