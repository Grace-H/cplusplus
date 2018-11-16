#include <iostream>
#include <cstring>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item{
 public:
  Item(char* newName);
  ~Item();
  char* getName();
 private:
  char* name;
};
#endif
