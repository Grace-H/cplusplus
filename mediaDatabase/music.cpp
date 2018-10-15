#include <iostream>
#include "music.h"

using namespace std;

Music::Music(char* newtitle[], int* newyear, char* newartist[], char* newpublisher[], int* newduration){
  title = newtitle;
  year = newyear;
  artist = newartist;
  publisher = newpublisher;
  duration = newduration;
  type = 2;
}

int Music::getType(){
  return type;
}

char* Music::getTitle(){
  return title;
}

int* Music::getYear(){
  return year;
}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int* Music::getDuration(){
  return duration;
}
