#include <iostream>
#include <cstring>
#include <cstdlib>
#inlcude "Music.h"

using namespace std;

int main(){
  char* title[256] = new char[256];
  cin.get(title, 256);
  cin.get();
  int* year = new int;
  char* input[256];
  cin.get(input, 256);
  cin.get();
  year = atoi(input);
  char* artist[256] = new char[256];
  cin.get(artist, 256);
  cin.get();
  char* publisher[256] = new publisher[256];
  cin.get(publisher, 256);
  cin.get();
  int* duration = new int;
  cin.get(input, 256);
  cin.get();
  duration = atoi(input);
  Music song = new Music(title, year, artist, publisher, duration);
  cout << "title: " << song.getTitle() << endl;
