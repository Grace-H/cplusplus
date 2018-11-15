//header file for class Movie
//Author: Grace Hunter
//Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "media.h"

#ifndef MOVIE_H
#define MOVIE_H

using namespace std;

class Movie : public Media {
 public:
  Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, char* newrating);
  //int getType();
  //char* getTitle();
  ~Movie();
  virtual char* getDirector();
  // int getYear();
  virtual int getDuration();
  virtual char* getRating();
 private:
  //char* title;
  char* director;
    //int* year;
  int* duration;
  char* rating;
  //int type;
};
#endif
