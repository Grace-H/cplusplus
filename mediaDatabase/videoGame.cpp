//class Game, child of Media
//Author: Grace Hunter
//Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "videoGame.h"

using namespace std;

//constructor
Game::Game(char* newtitle, int* newyear, char* newpublisher, char* newrating) : Media(newtitle, newyear, 1){
  publisher = newpublisher;
  rating = newrating;
}

//destructor
Game::~Game(){
  delete [] publisher;
  delete [] rating;
}

//returns publisher
char* Game::getPublisher(){
  return publisher;
}

//returns rating
char* Game::getRating(){
  return rating;
}
