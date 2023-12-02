// header file for Media class
// Author: Grace Hunter
// Date: 14 November 2018

#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
 public:
  Media(char* newtitle, int* newyear, int newtype);
  virtual ~Media();
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
 private:
  char* title;
  int* year;
  int type;
};

#endif
