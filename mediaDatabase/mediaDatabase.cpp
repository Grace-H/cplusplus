#include <iostream>
#include <cstring>
#include <cstdlib>
#include "music.h"

using namespace std;

void addMusic();
void addMovie();
void addGame();

int main(){
  addMusic();
  return 0;
}

void addMusic(){
  char* title = new char[256];
  cin.get(title, 256);
  cin.get();
  //char** titleAddress = &title;
  //cout << titleAddress << endl;
  //title[255] = '\0';
  int* year = new int;
  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);
  char* artist = new char[256];
  cin.get(artist, 256);
  cin.get();
  char* publisher = new char[256];
  cin.get(publisher, 256);
  cin.get();
  int* duration = new int;
  cin.get(input, 256);
  cin.get();
  *duration = atoi(input);
  cout << title << *year << artist << publisher << *duration << endl;
  cout << "collected all info" << endl;
  Music* song = new Music(title, year, artist, publisher, duration);
  cout << "created song" << endl;
  cout << "title: " << song->getTitle() << endl;
}


void addMovie(){
}

void addGame(){
}
