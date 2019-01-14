#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(){
  //PLEASE PUT YOUR CODE HERE to call the function assigned
  int length = 256;
  char input[length];
  cin.get(input, length);
  cin.get();
  //cout << input << endl;
  //cout << isspace(input[0]) << endl;
  int lenStr = strlen(input);
  for(int x = 0; x < 5; x++){
  int i = 0;
  int first = 0;
  while (i < lenStr && isspace(input[i]) != 0){
    i++;
    first++;
  }
  //cout << first << endl;
  int second = 0;
  bool last = true; //first = true, second = false;
  while (i < lenStr){
    if(isspace(input[i]) != 0){
      if(last){
	second = i - 1;
	char original = input[first];
	input[first] = input[second];
	input[second] = original;
	//cout << input[first] << input[second] << endl;
      }
      else {
	first = i + 1;
      }
      //    cout << input << endl;
      last = !last;
    }
    if (last){
      i++;
    }
  }
  second = lenStr - 1;
  char original = input[first];
  input[first] = input[second];
  input[second] = original;
  //cout << input[first] << input[second] << endl;
  cout << input << endl;
  }
  return 0;
}
