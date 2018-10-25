#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

Music::Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration){
  //cout << newtitle << *newyear << newartist << newpublisher << *newduration << endl;  
  title = newtitle;
  cout << "added title" << endl;
  year = newyear;
  cout << "added year" << endl;
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
  return *year;
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
