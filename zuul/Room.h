#include <iostream>
#include <cstring>
#include <map>

using namespace std;

class Room{
 public:
  Room(char newInfo);
  ~Room();
  void addExit(char exit, Room* target);
  void printInfo();
 private:
  map<char, Room*> exits;
  char info;
};
