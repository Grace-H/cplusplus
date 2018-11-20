#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"
#include <vector>
#include "Item.h"

using namespace std;

//constructor
Room::Room(char* newInfo){
  //cout << newInfo << endl;
  //strcpy(info, newInfo);
  info = newInfo;  
  //cout << info << endl;
}

Room::~Room(){
  //delete [] info;
}

void Room::addItem(Item* item){
  inventory.push_back(item);
}

void Room::addExit(char* exit, Room* target){
  exits.insert(pair<char*, Room*>(exit, target));
  Room* result = exits[exit];
  //cout << "This is " << exit << ": " << endl;
  //result->printInfo();
}

void Room::printInfo(){
  cout << info << endl;
  if(exits.empty()){
    cout << "There are no exits! You are trapped!" << endl;
  }
  else{
    cout << "You can go: ";
    for(map<char*,Room*>::iterator it = exits.begin(); it != exits.end(); it++){
      cout << it->first << " ";
    }
    cout << endl;
  }
}
