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

//destructor
Room::~Room(){
  delete [] info;
}

//add an item to the room
void Room::addItem(Item* item){
  inventory.push_back(item);
}

int Room::lenInventory(){
  return inventory.size();
}

bool Room::hasItem(Item* item){
  for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
    if ((*it) == item){
      return true;
    }
    else{
      return false;
    }
  }
}

//find and remove an item from the room
void Room::dropItem(Item* item){  
  vector<Item*>::iterator it = inventory.begin();
  while(it != inventory.end()){
    if(*it == item){
      inventory.erase(it);
      it = inventory.end();
    } else {
      it++;
    }
  }
}

//return room asscoiated with exit
Room* Room::getRoom(char* exit){
  if(exits.count(exit) == 1){
    return exits[exit];
  }
  else {
    return NULL;
  }
}

//add an exit to the room
void Room::addExit(char* exit, Room* target){
  exits.insert(pair<char*, Room*>(exit, target));
  Room* result = exits[exit];
  //cout << "This is " << exit << ": " << endl;
  //result->printInfo();
}

//print its own description, including info, exits, and items
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
  if(!inventory.empty()){
    cout << "There are items: ";
    for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++){
      cout << (*it)->getName() << " ";
    }
    cout << endl;
  }
}
