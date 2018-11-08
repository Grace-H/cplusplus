#include <iostream>
#include <cstring>
#include "media.h"

#ifndef MUSIC_H
#define MUSIC_H
using namespace std;

class Music : public Media {
 public:
  Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration);
  //int getType();
  //virtual char* getTitle();
  //virtual int getYear();
  virtual char* getArtist();
  virtual char* getPublisher();
  virtual int getDuration();
 private:
  char* artist;
  char* publisher;
  int* duration;
  int type; 
};

#endif
