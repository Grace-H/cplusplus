#include <iostream>

using namespace std;

void printBoard(int board[3][3]);
void clearBoard(int &board[3][3]);
int turn(int &board[3][3]);
void getMove(int &move[2]);
int checkWin(int board[3][3]);

main(){
  int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  clearBoard(&board);
  printBoard(board);
  
}

void printBoard(int board[3][3]){
  cout << " a b c" << endl;
  for (int i = 0; i < 3; i++){
    cout << i + 1 << " " << board[i][0] << " " << board [i][1] << " " << board[i][2] << endl;
  }
}

void clearBoard(int &board[3][3]){
  board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
}
