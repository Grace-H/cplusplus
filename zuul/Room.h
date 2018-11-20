#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room{
 public:
  Room(char* newInfo);
  ~Room();
  void addItem(Item* item);
  void addExit(char* exit, Room* target);
  void printInfo();
 private:
  map<char*, Room*> exits;
  char* info;
  vector<Item*> inventory;
};

#endif
