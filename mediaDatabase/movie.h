// header file for class Movie
// Author: Grace Hunter
// Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "media.h"

#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie : public Media {
 public:
  Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, char* newrating);
  ~Movie();
  virtual char* getDirector();
  virtual int getDuration();
  virtual char* getRating();
 private:
  char* director;
  int* duration;
  char* rating;
};
#endif
