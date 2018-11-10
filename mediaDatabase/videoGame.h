#include <iostream>
#include <cstring>
#include "media.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game : public Media {
 public:
  Game(char* newtitle, int* newyear, char* newpublisher, int* newduration);
  virtual char* getPublisher();
  virtual int getRating();
 private:
  char* publisher;
  int* rating;
  int type; 
};

#endif
