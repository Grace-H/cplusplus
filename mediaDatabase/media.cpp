// Media class - represents the information of a piece of media
// Author: Grace Hunter
// Date: 14 November 2018

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

// constructor
Media::Media(char* newtitle, int* newyear, int newtype){
  title = newtitle;
  year = newyear;
  type = newtype;
}

// destructor
Media::~Media() {
  delete [] title;
  delete year;
}

// returns media type
int Media::getType() {
  return type;
}

// returns title
char* Media::getTitle() {
  return title;
}

// returns year
int Media::getYear() {
  return *year;
}
