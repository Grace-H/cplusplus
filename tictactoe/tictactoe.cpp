/*TicTacToe game in command line for two players
 *Author: Grace Hunter
 *Date: 27 September 2018
 */

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void printBoard(char** board);
void clearBoard(char** board);
char turn(char** board, int* move, char player);
void getMove(int* move, char player);
char checkWin(char** board);

const char X = 'X';
const char O = 'O';
const char tie = 'T';

main(){

  //pointer to array of pointers which holds board
  char** board;
  board = new char*[3];
  for (int i = 0; i < 3; i++){
    board[i] = new char[3];
  }
  
  //pointer that points to array that holds where user wants to play
  int* move = new int[3];

  //number of wins for each player 
  int xWins = 0;
  int oWins = 0;
  int tieWins = 0;

  //while the player still want to play
  bool stillPlaying = true;
  while(stillPlaying){ 

    //reset board
    clearBoard(board);

    bool won = false;
    char whoseTurn = X;
    char result = 'N'; //result of checkWin after a turn

    //while no one has one
    while(!won){
      printBoard(board);

      //turn
      result = turn(board, move, whoseTurn);

      //evaluate result, break out of while if won and display message
      if(result == X){
	printBoard(board);
	xWins++;
	won = true;
	cout << "Congratulations Player " << result << ", you win!" << endl;
      }else if(result == O){
	printBoard(board);
	oWins++;
	won = true;
	cout << "Congratulations Player " << result << ", you win!" << endl;
      }else if(result == tie){
	printBoard(board);
	tieWins++;
	won = true;
	cout << "It's a tie!" << endl;
      }

      //change whose turn
      if(whoseTurn == X){
	whoseTurn = O;
      } else{
	whoseTurn = X;
      }
    }

    //tell how many wins and ask to play again
    cout << "X wins: " << xWins << "\tO wins: " << oWins << "\tTies: " << tieWins << endl;
    cout << "Would you like to play again? 'y' or 'n'" << endl;
    char playAgain[256];
    cin.get(playAgain, 256);
    cin.get();
    if(playAgain[0] == 'n'){
      stillPlaying = false;
      cout << "Thanks for playing. Goodbye." << endl;
    }
  }

  //delete pointers
  for(int i = 0; i < 3; i++){
    delete[] board[i];
  }
  delete[] board;
  delete[] move;
  
  return 0;
}

//print out the board like this:
/*  a b c
 *1 
 *2
 *3
 */
void printBoard(char** board){
  cout << "  a b c" << endl;
  for (int i = 0; i < 3; i++){
    cout << i + 1 << " " << board[i][0] << " " << board [i][1] << " " << board[i][2] << endl;
  }
}

//fill board array with ' ' chars
void clearBoard(char** board){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
}

//get a user's move, place in board, and check if someone won
char turn(char** board, int* move, char player){

  //get move from player
  bool valid = false;
  cout << "Player " << player << ", enter a move: " << endl;
  while(!valid){
    getMove(move, player);

    //check if that spot is blank
    if(isspace(board[move[0]][move[1]])){
      board[move[0]][move[1]] = player;
      valid = true;
    }
    else {
      cout << "Someone has played there. Please try again:" << endl;
    }
  }

  //return the result of a check for wins
  return checkWin(board);
}

//get and evaluate a move from the player and store in move array
void getMove(int* move, char player){
  bool valid = true;
  char input[256];

  do{
     valid = true;
     //read in a move
     cin.get(input, 256);
     cin.get();

     input[0] = toupper(input[0]);
     //check if character is valid
     if(input[0] == 'A'){
       move[1] = 0;
     } else if(input[0] == 'B'){
       move[1] = 1;
     } else if(input[0] == 'C'){
       move[1] = 2;
     } else{
       valid = false;
     }
     
     //check if number is valid
     if(input[1] == '1'){
       move[0] = 0;
     } else if(input[1] == '2'){
       move[0] = 1;
     } else if(input[1] == '3'){
       move[0] = 2;
     } else{
       valid = false;
     }

     //ask for another if not vaild
     if(valid == false){
       cout << "Your input was not a valid place to play. Please try again: " << endl;
     }

     //run above loop until user enters a valid input
  } while(!valid);
}

//check rows, columns, diagonals for wins or ties
char checkWin(char** board){
  //check rows
  for(int i = 0; i < 3; i++){
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
      return board[i][0];
    }
  }
  
  //check columns
  for(int i = 0; i < 3; i++){
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
      return board[0][i];
    }
  }
  
  //check diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
    return board[0][0];
  }
  if(board[0][2] == board [1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
    return board[0][2];
  }

  //check ties
  bool isTie = true;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(isspace(board[i][j])){
	  isTie = false;
      }
    }
  }
  //return tie if tie was found
  if(isTie){
    return tie;
  }
  //return an N if nothing was found
  else{
    return 'N';
  }
}
