#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media{
 public:
  Media(char* newtitle, int* newyear, int newtype);
  int getType();
  char* getTitle();
  int getYear();
 private:
  char* title;
  int* year;
  int type;
};

#endif
