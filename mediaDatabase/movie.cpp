#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

Movie::Movie(char* newtitle, char* newdirector, int* newyear, int* newduration, int* newrating) : Media(newtitle, newyear, 1){
  //cout << newtitle << *newyear << newartist << newpublisher << *newduration << endl;  
  //title = newtitle;
  //cout << "added title" << endl;
  director = newdirector;
  //year = newyear;
  //cout << "added year" << endl;
  duration = newduration;
  rating = newrating;
  //type = 1;
}

//int Movie::getType(){
//return type;
//}

//char* Movie::getTitle(){
//return title;
//}

//int Movie::getYear(){
//return *year;
//}

char* Movie::getDirector(){
  return director;
}

int Movie::getDuration(){
  return *duration;
}

int Movie::getRating(){
  return *rating;
}

