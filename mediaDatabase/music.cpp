#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration) : Media(newtitle, newyear, 2){
  artist = newartist;
  publisher = newpublisher;
  duration = newduration;
}

Music::~Music(){
  delete [] artist;
  delete [] publisher;
  delete duration;
}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return *duration;
}
