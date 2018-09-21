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
  char** board;
  board = new char*[3];
  for (int i = 0; i < 3; i++){
    board[i] = new char[3];
  }

  int* move = new int[3];
  bool stillPlaying = true;
  while(stillPlaying){ 
    clearBoard(board);
    
    //number of wins for each player 
    int xWins = 0;
    int oWins = 0;
    int tieWins = 0;
    
    bool won = false;
    char whoseTurn = X;
    char result = 'N'; //result of checkWin after a turn

    while(!won){
      printBoard(board);

      //turn
      result = turn(board, move, whoseTurn);

      //evaluate result, break if won and display message
      if(result == X){
	xWins++;
	won = true;
	cout << "Congratulations Player " << result << ", you win!" << endl;
      }else if(result == O){
	oWins++;
	won = true;
	cout << "Congratulations Player " << result << ", you win!" << endl;
      }else if(result == tie){
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
    char playAgain = 'n';
    cout << "Would ou like to play again? 'y' or 'n'" << endl;
    cin >> playAgain;
    if(playAgain == 'n'){
      stillPlaying == false;
      cout << "Thanks for playing. Goodbye." << endl;
    }
  }
  return 0;
}
void printBoard(char** board){
  cout << "  a b c" << endl;
  for (int i = 0; i < 3; i++){
    cout << i + 1 << " " << board[i][0] << " " << board [i][1] << " " << board[i][2] << endl;
  }
}

void clearBoard(char** board){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = ' ';
    }
  }
}

char turn(char** board, int* move, char player){
  bool valid = false;
  cout << "Player " << player << ", enter a move: " << endl;
  while(!valid){
    getMove(move, player);
    if(isspace(board[move[0]][move[1]])){
      board[move[0]][move[1]] = player;
      cout << "changed board" << endl;
      cout << "player: " << player << endl;
      valid = true;
    }
    else {
      cout << "Someone has played there. Please try again:" << endl;
    }
  }
  return checkWin(board);
}

void getMove(int* move, char player){
  char input[3];
  bool valid = true;
  do{
     valid = true;
     cin.get(input, 3);
     cin.get();
     cout << "input = " << input << endl;
     input[0] = toupper(input[0]);
     cout << "input0 = " << input[0] << endl;
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
     
     //check if numberis valid
     cout << "input1 = " << input[1] << endl;
     if(input[1] == '1'){
       move[0] = 0;
     } else if(input[1] == '2'){
       move[0] = 1;
     } else if(input[1] == '3'){
       move[0] = 2;
     } else{
       valid = false;
     }

     if(valid == false){
       cout << "Your input was not a valid place to play. Please try again: " << endl;
     }
     
  } while(!valid);
}

char checkWin(char** board){
  //check rows
  for(int i = 0; i < 3; i++){
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
      cout << "win found in row " << i << endl;
      return board[i][0];
    }
  }
  
  //check columns
  for(int i = 0; i < 3; i++){
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
      cout << "win found in column " << i << endl;
      return board[0][i];
    }
  }
  
  //check diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
    cout << "win found in diagonal " << 1 << endl;
    return board[0][0];
  }
  if(board[0][2] == board [1][1] && board[1][1] == board[0][2] && board[0][2] != ' '){
    cout << "win found in diagonal " << 2 << endl;
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
  if(isTie){
    return tie;
  }
  else{
    return 'N';
  }
}
