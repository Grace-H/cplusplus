#include <iostream>
#include <cstring>

using namespace std;

class Music {
 public:
  Music(char* newtitle[], int* newyear, char* newartist[], char* newpublisher[], int* newduration);
  int getType();
  char* getTitle();
  int* getYear();
  char* getArtist();
  char* getPublisher();
  int* getDuration();
 private:
  char* title[];
  int* year;
  char* artist[];
  char* publisher[];
  char* duration[];
  int type; 
};
