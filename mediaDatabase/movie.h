#include <iostream>
#include <cstring>

using namespace std;

class Movie {
 public:
  Movie(char* title, char* director, int* year, int* duration, int* rating);
  int getType();
  char* getTitle();
  char* getDirector();
  int getYear();
  int getDuration();
  int getRating();
 private:
  char* title;
  char* director,
  int* year;
  int* duration;
  int* rating;
  int type;
};
