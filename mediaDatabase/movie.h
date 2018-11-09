#include <iostream>
#include <cstring>
#include "media.h"

#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie : public Media {
 public:
  Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, int* newrating);
  //int getType();
  //char* getTitle();
  virtual char* getDirector();
  // int getYear();
  virtual int getDuration();
  virtual int getRating();
 private:
  //char* title;
  char* director;
    //int* year;
  int* duration;
  int* rating;
  //int type;
};
#endif
