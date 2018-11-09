#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "media.h"
//#include "movie.h"
#include "music.h"

using namespace std;

void printMedia(vector<Media*>* media);
void printObj(Media* media);
void searchMedia(vector<Media*>* media);
void addMusic(vector<Media*>* media);
void addMovie();
void addGame();

int main(){

  vector<Media*>* media = new vector<Media*>;
  
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

    if(strcmp(input, addStr) == 0){
      cout << "'MOVIE' 'MUSIC' or 'GAME'?" << endl;
      cin.get(input, 256);
      cin.get();
      for(int i = 0; i < 256; i++){
	input[i] = toupper(input[i]);
      }
      if(strcmp(input, movieStr) == 0){
	//addMovie();
      }else if(strcmp(input, musicStr) == 0){
	addMusic(media);
	printMedia(media);
      }else if(strcmp(input, gameStr) == 0){
      }else{
	cout << "Not a type of media" << endl;
      }
    }else if (strcmp(input, deleteStr) == 0){
    }else if (strcmp(input, searchStr) == 0){
      searchMedia(media);
    }else if (strcmp(input, quitStr) == 0){
    }else{
    }
  }
  return 0;
}

void printMedia(vector<Media*>* media){
  for(vector<Media*>::iterator it = media->begin(); it != media->end(); ++it){
    cout << (*it)->getTitle() << (*it)->getYear() << (*it)->getType() << endl;
  }
}

void printObj(Media* media){
  int type = media->getType();
  if(type ==2){
    Music* song = (Music*)(media);
    cout << "Movie: " << song->getTitle() << ", " << song->getArtist() << ", " << song->getYear() << ", " << song->getPublisher() << ", " << song->getDuration() << "min" << endl;
  }
}

void searchMedia(vector<Media*>* media){
  char input[256];
  cout << "Enter a title or year" << endl;
  cin.get(input, 256);
  cin.get();
  char title[256];
  for(int i = 0; i < strlen(input); i++){
    title[i] = toupper(input[i]);
  }
  int year = atoi(input);
  //cout << "Title: " << title << endl;
  for(vector<Media*>::iterator it = media->begin(); it != media->end(); it++){
    //cout << (*it)->getTitle() << endl;
    char* itTitle = (*it)->getTitle();
    for(int i = 0; i < strlen(itTitle); i++){
      itTitle[i] = toupper(itTitle[i]);
    }
    if(strcmp(input, itTitle)){
      printObj(*it);
    }
    else if(year == (*it)->getYear()){
      printObj(*it);
    }
  }
}
void addMusic(vector<Media*>* media){
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
  cout << "type" << song->getType() << endl;
  cout << "title: " << song->getTitle() << endl;
  media->push_back(song);
}

/*
void addMovie(){
  char* title = new char[256];
  cin.get(title, 256);
  cin.get();
  int* year = new int;
  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);
  char* director = new char[256];
  cin.get(director, 256);
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

void addGame(){
}
*/
