/*
 *Header file for Class Item
 *Author: Grace Hunter
 *Date: 16 November 2018
 */

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
