#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media {
 public:
  Music(char* newtitle, int* newyear, char* newartist, char* newpublisher, int* newduration);
  int getType();
  char* getTitle();
  int getYear();
  char* getArtist();
  char* getPublisher();
  int getDuration();
 private:
  char* title;
  int* year;
  char* artist;
  char* publisher;
  int* duration;
  int type; 
};
