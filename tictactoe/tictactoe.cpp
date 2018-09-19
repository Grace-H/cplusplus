#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void printBoard(char** board);
void clearBoard(char** board);
int turn(char** board, int* move, int player);
void getMove(int* move, int player);
int checkWin(char** board);
const int X = 1;
const int O = 2;

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
    printBoard(board);

    bool won = false;
    int whoseTurn = X;
    while(!won){
      //turn
      turn(board, move, whoseTurn);
      //evaluate result, break if won and display message
      //change whose tur
      won = true;
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

int turn(char** board, int* move, int player){
  bool valid = false;
  while(!valid){
    getMove(move, player);
    if(isspace(board[move[0]][move[1]])){
      board[move[0]][move[1]] = player;
      valid = true;
    }
  }
  return 2;
  
}

void getMove(int* move, int player){
  cout << "Player " << player << ", enter a move: " << endl;
  char input[3];
  bool valid = true;
  do{
     cin.get(input, 3);
     cin.get();
     cout << "input = " << input << endl;
     input[0] = toupper(input[0]);
     cout << "input0 = " << input[0] << endl;
     //check if character is valid
     if(input[0] == 'A'){
       move[0] = 0;
     } else if(input[0] == 'B'){
       move[0] = 1;
     } else if(input[0] == 'C'){
       move[0] = 2;
     } else{
       valid = false;
     }
     
     //check if numberis valid
     cout << "input1 = " << input[1] << endl;
     if(input[1] == '1'){
       move[1] = 0;
     } else if(input[1] == '2'){
       move[1] = 1;
     } else if(input[1] == '3'){
       move[1] = 2;
     } else{
       valid = false;
     }

     if(valid == false){
       cout << "Your input was not a valid place to play. Please try again: " << endl;
     }
     
  } while(!valid);
}
