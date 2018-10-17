#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(char newtitle[256], int newyear, char newartist[256], char newpublisher[256], int newduration){
  strcpy(title, newtitle);
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

int Music::getYear(){
  return year;
}

char* Music::getArtist(){
  return artist;
}

char* Music::getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}
