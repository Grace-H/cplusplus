#include <iostream>
#include <cstring>

using namespace std;

class Media{
 public:
  Music(char* newtitle, int* newyear);
  int getType();
  char* getTitle();
  int getYear();
 private:
  char* title;
  int* year;
  int type;
};
