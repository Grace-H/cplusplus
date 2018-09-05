#include <iostream> //print things in and out to the console

using namespace std;

int main(){
  int input = 0;
  cin >> input;
  if(input == 3){
    cout << "You entered a 3!" << endl;
  }
  while(input <= 5){
    cout << input << endl;
    input++;
  };
  for(int input = 0; input <= 5; input++){
    cout << input << endl;
  }
  cout << input << endl;
  return 0; //correct response, return something else in case of error
}
