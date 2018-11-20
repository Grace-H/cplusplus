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