//header file for Game class
//Author: Grace Hunter
//Date: 2018

#include <iostream>
#include <cstring>
#include "media.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game : public Media {
 public:
  Game(char* newtitle, int* newyear, char* newpublisher, char* newrating);
  ~Game();
  virtual char* getPublisher();
  virtual char* getRating();
 private:
  char* publisher;
  char* rating;
  int type; 
};

#endif
