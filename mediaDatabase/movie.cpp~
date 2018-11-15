#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//constructor for Movie, also creates parent Media
Movie::Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, int* newrating) : Media(newtitle, newyear, 3){
  director = newdirector;
  duration = newduration;
  rating = newrating;
}

//returns director
char* Movie::getDirector(){
  return director;
}

//returns duration
int Movie::getDuration(){
  return *duration;
}

//returns rating
int Movie::getRating(){
  return *rating;
}

