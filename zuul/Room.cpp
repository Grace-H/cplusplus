#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"

using namespace std;

//constructor
Room::Room(char newInfo){
  info = newInfo;
}

Room::~Room(){
  delete [] info;
}

void Room::addExit(char exit, Room* target){
  exits[exit] = target;
}

void Room::printInfo(){
  cout << "You are in the " << info << endl;
  if(exits.empty()){
    cout << "There are no exits! You are trapped!" << endl;
  }
  else{
    cout << "There are exits: ";
    for(map<char,Room*>::iterator it = exits.begin(); it != exits.end(); it++){
      cout << it->first;
    }
    cout << endl;
  }
}
