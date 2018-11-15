//class Movie, child of Media
//Author: Grace Hunter
//Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//constructor
Music::Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration) : Media(newtitle, newyear, 2){
  artist = newartist;
  publisher = newpublisher;
  duration = newduration;
}

//destructor
Music::~Music(){
  delete [] artist;
  delete [] publisher;
  delete duration;
}

//returns artist
char* Music::getArtist(){
  return artist;
}

//returns publisher
char* Music::getPublisher(){
  return publisher;
}

//returns duration
int Music::getDuration(){
  return *duration;
}
