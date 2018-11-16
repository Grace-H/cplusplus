#include <iostream>
#include <cstring>
#include "Item.h"
#include "Room.h"

int main(){
  Room* library = new Room("library");
  Room* lab = new Room("lab");
  library->addExit("EAST", lab);
  library->printInfo();
  delete lab;
  delete library;
  return 0;
}
