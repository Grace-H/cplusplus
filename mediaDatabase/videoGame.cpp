#include <iostream>
#include <cstring>
#include "videoGame.h"

using namespace std;

Game::Game(char* newtitle, int* newyear, char* newpublisher, int* newrating) : Media(newtitle, newyear, 1){
  publisher = newpublisher;
  rating = newrating;
}

char* Game::getPublisher(){
  return publisher;
}

int Game::getRating(){
  return *rating;
}
