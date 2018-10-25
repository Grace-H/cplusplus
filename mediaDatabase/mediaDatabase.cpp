#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include "movie.h"
#include "music.h"

using namespace std;

void addMusic();
void addMovie();
void addGame();

int main(){
  bool stillPlaying = true;
  char input[256];

  char deleteStr[20] = "DELETE";
  char addStr[20] = "ADD";
  char searchStr[20] = "SEARCH";
  char quitStr[20] = "QUIT";

  char movieStr[20] = "MOVIE";
  char musicStr[20] = "MUSIC";
  char gameStr[20] = "GAME";
  
  while(stillPlaying){
    cout << "Ready for command." << endl;
    cin.get(input, 256);
    cin.get();

    //make all caps
    for(int i = 0; i < 256; i++){
      input[i] = toupper(input[i]);
    }

    if(strcmp(input, addStr[20]) == 0){
      cout << "'MOVIE' 'MUSIC' or 'GAME'?" << endl;
      for(int i = 0; i < 256; i++){
	input[i] = toupper(input[i]);
      }
      if(strcmp(input, movieStr) == 0){
      }else if(strcmp(input, musicStr) == 0){
	addMusic();
      }else if(strcmp(input, gameStr) == 0){
      }else{
	cout << "Not a type of media" << endl;
      }
    }else if (strcmp(input, deleteStr) == 0){
    }else if (strcmp(input, searchStr) == 0){
    }else if (strcmp(input, quitStr) == 0){
    }else{
    }
      

  }
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
