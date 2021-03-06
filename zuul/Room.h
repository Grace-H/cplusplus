/*
 *Header file for Class Room
 *Author: Grace Hunter
 *Date: 16 November 2018
 */

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
  int lenInventory();
  bool hasItem(Item* item);
  void dropItem(Item* item);
  Room* getRoom(char* exit);
  void addExit(char* exit, Room* target);
  void printInfo();
 private:
  map<char*, Room*> exits;
  char* info;
  vector<Item*> inventory;
};

#endif
