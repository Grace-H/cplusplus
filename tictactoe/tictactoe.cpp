#include <iostream>

using namespace std;

void printBoard(int** board);
void clearBoard(int** board);
int turn(int** board, int player);
void getMove(int* move, int player);
int checkWin(int** board);
const int X = 1;
const int O = 2;

main(){
  int** board;
  board = new int*[3];
  for (int i = 0; i < 3; i++){
    board[i] = new int[3];
  }

  int* move = new int[3];
  
  clearBoard(board);
  printBoard(board);
}

void printBoard(int** board){
  cout << "  a b c" << endl;
  for (int i = 0; i < 3; i++){
    cout << i + 1 << " " << board[i][0] << " " << board [i][1] << " " << board[i][2] << endl;
  }
}

void clearBoard(int** board){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = 0;
    }
  }
}

int turn(int** board, int player){
  
  
}

void getMove(int* move, int player){
  cout << "Player " << player << "enter a move: " << endl;
}
