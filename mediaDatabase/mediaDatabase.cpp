#include <iostream>
#include <cstring>
#include <cstdlib>
#include "music.h"

using namespace std;

int main(){
  char* title = new char[256];
  cin.get(title, 256);
  cin.get();
  int* year = new int;
  char input[256];
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);
  char* artist = new char[256];
  cin.get(artist, 256);
  cin.get();
  char* publisher = new char[256];
  cin.get(publisher, 256);
  cin.get();
  int* duration = new int();
  cin.get(input, 256);
  cin.get();
  *duration = atoi(input);
  cout << "collected all info" << endl;
  Music* song = new Music(title, *year, artist, publisher, *duration);
  cout << "created song" << endl;
  cout << "title: " << song->getTitle() << endl;
  return 0;
}
