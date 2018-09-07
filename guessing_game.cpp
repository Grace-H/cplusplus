/*Guessing game: the computer selects a random number and the 
 *user tries to guess it in as few guesses as possible
 *Author: Grace Hunter
 *Date: 07 September 2018
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
  bool still_playing = true;
  while (still_playing){

    //generate a random number
    srand(time(NULL));
    int num = rand()%100;
    
    int guesses = 0; //number of times the user has tried to guess
    bool won = false; //whether the user has guessed the number yet
    
    //read in the first guess
    cout << "I have a number between 0 and 100! Try and guess my number:" << endl;
    int input = 0;
    cin >> input;

    //while the user hasn't guessed the number
    while (!won){
      guesses++; //increment guesses

      //tell user how their guess compares to number
      if (input < num){
	cout << "Too low! Try again:" << endl;
	cin >> input;
      }
      else if (input > num){
	cout << "Too high! Try again:" << endl;
	cin >> input;
      }
      else if (input == num){
	won = true;
	cout << "You guessed my number in " << guesses << " guesses!" << endl;
      }
    }

    //ask whether to start a new game, and reset if they want to
    cout << "Would you like to play again? 'y' or 'n'" << endl;
    char play_again = 'a';
    cin >> play_again;
    if (play_again == 'n'){
      still_playing = false;
    }
  }
  return 0;
}
