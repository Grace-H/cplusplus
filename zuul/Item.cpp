/*
 *Class Item: part of projects Zuul
 *Returns its name
 *Author: Grace Hunter
 *Date: 16 November 2018
 */

#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

//constructor
Item::Item(char* newName){
  name = newName;
}

//destructor
Item::~Item(){
  delete [] name;
}

char* Item::getName(){
  return name;
}
