#include <iostream>
#include <cstring>
#include "media.h"

#ifndef MUSIC_H
#define MUSIC_H
using namespace std;

class Music : public Media {
 public:
  Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration);
  ~Music();
  virtual char* getPublisher();
  virtual int getDuration();
  virtual char* getArtist();
 private:
  char* artist;
  char* publisher;
  int* duration;
  int type; 
};

#endif
