//class Movie, child of Media
//Author: Grace Hunter
//Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//constructor for Movie, also creates parent Media
Movie::Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, char* newrating) : Media(newtitle, newyear, 3){
  director = newdirector;
  duration = newduration;
  rating = newrating;
}

//destructor
Movie::~Movie(){
  delete [] director;
  delete duration;
  delete [] rating;
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
char* Movie::getRating(){
  return rating;
}

