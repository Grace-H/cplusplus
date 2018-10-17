#include <iostream>
#include <cstring>

using namespace std;

class Music {
 public:
  Music(char newtitle[256], int newyear, char newartist[256], char newpublisher[256], int newduration);
  int getType();
  char* getTitle();
  int getYear();
  char* getArtist();
  char* getPublisher();
  int getDuration();
 private:
  char* title;
  int year;
  char* artist;
  char* publisher;
  int duration;
  int type; 
};
