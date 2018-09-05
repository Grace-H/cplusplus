#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  bool still_playing = true;
  while (still_playing){
    srand(time(NULL));
    int num = rand()%100 + 1;
    bool guessed = false;
    cout << "I have a number between one and one hundred! Try and guess my number:" << endl;
    int input = 0;
    cin >> input;
    while (!guessed){
      if (input < num){
	cout << "Too low! Try again:" << endl;
	cin >> input;
      }
      else if (input > num){
	cout << "Too high! Try again:" << endl;
	cin >> input;
      }
      else if (input == num){
	guessed = true;
	cout << "You guessed my number!" << endl;
      }
    }
    cout << "Would you like to play again? 'y' or 'n'" << endl;
    char play_again = 'a';
    cin >> play_again;
    if (play_again == 'n'){
      still_playing = false;
    }
  }
  return 0;
}
