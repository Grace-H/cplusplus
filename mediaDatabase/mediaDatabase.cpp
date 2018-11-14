#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cctype>
#include "media.h"
#include "movie.h"
#include "music.h"
#include "videoGame.h"

using namespace std;

void printMedia(vector<Media*>* media);
void printObj(Media* media);
void searchMedia(vector<Media*>* media);
void addMusic(vector<Media*>* media);
void addMovie(vector<Media*>* media);
void addGame(vector<Media*>* media);

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
    cout << "Ready for command. 'DELETE' 'ADD' 'SEARCH' 'QUIT'" << endl;
    cin.get(input, 256);
    cin.get();
    
    //make all caps
    for(int i = 0; i < 256; i++){
      input[i] = toupper(input[i]);
    }

    //if add
    if(strcmp(input, addStr) == 0){
      //get type of media to add
      cout << "'MOVIE' 'MUSIC' or 'GAME'?" << endl;
      cin.get(input, 256);
      cin.get();
      for(int i = 0; i < 256; i++){
	input[i] = toupper(input[i]);
      }
      //if movie
      if(strcmp(input, movieStr) == 0){
	addMovie(media);
	//printMedia(media);
      //if music
      }else if(strcmp(input, musicStr) == 0){
	addMusic(media);
	//printMedia(media);
      //if videogame
      }else if(strcmp(input, gameStr) == 0){
	addGame(media);
      }else{
	cout << "Not a type of media" << endl;
      }

    //if delete      
    }else if (strcmp(input, deleteStr) == 0){
      deleteMedia(media);
    //if search
    }else if (strcmp(input, searchStr) == 0){
      searchMedia(media);

    //iif quit
    }else if (strcmp(input, quitStr) == 0){
      quit(media);
    //command not recognized
    }else{
      cout << "Not a command." << endl;
    }
  }
  return 0;
}

//prints out all media objects
void printMedia(vector<Media*>* media){
  for(vector<Media*>::iterator it = media->begin(); it != media->end(); ++it){
    cout << (*it)->getTitle() << (*it)->getYear() << (*it)->getType() << endl;
  }
}

//prints out data associated with a media object passed in
void printObj(Media* media){
  int type = media->getType();
  if (type == 1) {
    Game* game = (Game*)(media);
    cout << "Type: Video Game" << endl;
    cout << "Title: " << game->getTitle() << endl;
    cout << "Publisher: " << game->getPublisher() << endl;
    cout << "Year: " << game->getYear() << endl;
    cout << "Rating: " << game->getRating() << endl;
    cout << endl;
  } else if(type == 2){
    Music* song = (Music*)(media);
    cout << "Type: Music" << endl;
    cout << "Title: " << song->getTitle() << endl;
    cout << "Artist: " << song->getArtist() << endl;
    cout << "Year: " << song->getYear() << endl;
    cout << "Publisher: " << song->getPublisher() << endl;
    cout << "Duration: " << song->getDuration() << " min" << endl;
    cout << endl;
  } else if (type == 3) {
    Movie* movie = (Movie*)(media);
    cout << "Type: Movie" << endl;
    cout << "Title: " << movie->getTitle() << endl;
    cout << "Year: " << movie->getYear() << endl;
    cout << "Director: " << movie->getDirector() << endl;
    cout << "Duration: " << movie->getDuration() << endl;
    cout << "Rating: " << movie->getRating() << endl;
    cout << endl;
  }
}

//searchMedia: takes a search term and tried to find matching media objects
void searchMedia(vector<Media*>* media){
  //ask for search term
  char input[256];
  cout << "Enter a title or year:" << endl;
  cin.get(input, 256);
  cin.get();
  cout << endl;
  char title[256];
  //capitalize each char and add to array for title
  for(int i = 0; i < strlen(input); i++){
    title[i] = toupper(input[i]);
  }
  title[strlen(input)] = '\0';

  //also convert it to int in case it's the year
  int year = atoi(input);
  
  bool anyFound = false; //tracks if any are found so if none are user can be informed  
  for(vector<Media*>::iterator it = media->begin(); it != media->end(); it++){
    //get and capitalize the title of media object
    char itTitle[256];
    strcpy(itTitle, (*it)->getTitle());
    for(int i = 0; i < strlen(itTitle); i++){
      itTitle[i] = toupper(itTitle[i]);
    }
    //check for name match
    if(strcmp(title, itTitle) == 0){
      if (!anyFound){
	cout << "Match(es) found: " << endl;
      }
      //cout << "Name match" << endl;
      printObj(*it);
      anyFound = true;
    }
    //check for year match
    else if(year == (*it)->getYear()){
      if (!anyFound){
	cout << "Match(es) found: " << endl;
      }
      //cout << "Year match: " << (*it)->getYear() << endl;      
      printObj(*it);
      anyFound = true;
    }
  }
  
  //tell user if none are found
  if(!anyFound){
    cout << "No matching media." << endl;
    cout << endl;
  }
}

void addMusic(vector<Media*>* media){
  //get title  
  cout << "Enter the title: " << endl;
  char* title = new char[256];
  cin.get(title, 256);
  cin.get();

  //get year
  cout << "Enter the year: " << endl;
  int* year = new int;
  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);

  //get artist
  cout << "Enter the artist: " << endl;
  char* artist = new char[256];
  cin.get(artist, 256);
  cin.get();

  //get publisher
  cout << "Enter the publisher: " << endl;
  char* publisher = new char[256];
  cin.get(publisher, 256);
  cin.get();

  //get duration
  cout << "Enter the duration (minutes): " << endl;
  int* duration = new int;
  cin.get(input, 256);
  cin.get();
  *duration = atoi(input);

  //create Music object and add to Media vector
  Music* song = new Music(title, year, artist, publisher, duration);
  media->push_back(song);
  cout << endl;
}

void addMovie(vector<Media*>* media){
  //get title
  cout << "Enter the title: " << endl;
  char* title = new char[256];
  cin.get(title, 256);
  cin.get();

  //get year
  cout << "Enter the year: " << endl;
  int* year = new int;
  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);

  //get director
  cout << "Enter the director: " << endl;
  char* director = new char[256];
  cin.get(director, 256);
  cin.get();
  
  //get rating
  cout << "Enter the rating (X/5): " << endl;
  int* rating = new int;
  cin.get(input, 256);
  cin.get();
  *rating = atoi(input);

  //get duration
  cout << "Enter the duration (minutes): " << endl;
  int* duration = new int;
  cin.get(input, 256);
  cin.get();
  *duration = atoi(input);
  
  //create Movie object and add to Media vector
  Movie* movie = new Movie(title, director, year, duration, rating);
  media->push_back(movie);
  cout << endl;
}

void addGame(vector<Media*>* media){
  //get title
  char* title = new char[256];
  cout << "Enter the title: " << endl;
  cin.get(title, 256);
  cin.get();

  //get year
  int* year = new int;
  char input[256];
  cout << "Enter the year: " << endl;
  cin.get(input, 256);
  cin.get();
  *year = atoi(input);

  //get publisher
  char* publisher = new char[256];
  cout << "Enter the publisher: " << endl;
  cin.get(publisher, 256);
  cin.get();

  //get rating
  int* rating = new int;
  cout << "Enter the rating (X/5): " << endl;
  cin.get(input, 256);
  cin.get();
  *rating = atoi(input);

  //create and add game to vector
  Game* game = new Game(title, year, publisher, rating);
  media->push_back(game);
  cout << endl;
}

