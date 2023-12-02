/*
 * Palindrome: reads in a string and determines if it is a palindrome
 * Author: Grace Hunter
 * Date: 11 September 2018
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {

  //read in a string
  char original[80];
  cin.get(original, 80);
  cin.get();
  
  int letterTotal = 0; //number of chars in entered word

  //loop through original, and if char is alphanumeric add to a new string, called input
  char input[80];
  int count = 0;
  while (original[count] != '\n' && count < 80 && original[count] != '\0') {
    if (isalnum(original[count])) {
      input[letterTotal] = toupper(original[count]);
      letterTotal++;
    }
    count++;
  }
  input[letterTotal] = '\0';

  //read chars of input backwards into another string, called comp
  char comp[80];
  for (int i=letterTotal - 1; i >= 0; i--) {
    comp[i] = input[letterTotal - i - 1];
  }
  comp[letterTotal] = '\0';

  //compare comp and input to determine if it is a palindrome
  if (strcmp(comp, input) == 0) {
    cout << "Palindrome." << endl;
  }
  else {
    cout << "Not a palindrome." << endl;
  }
  
  return 0;
}
