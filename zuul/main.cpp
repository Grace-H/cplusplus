/*
Zuul: A text-based adventure game set on the east coast
Objective: discover and collect all five items in under 3 minutes
Author: Grace Hunter
Date: 16 November 2018
*/

#include <iostream>
#include <cstring>
#include "Item.h"
#include "Room.h"

int main(){
  //direction char arrays, used for creating exits
  char* north = new char[6];
  strcpy(north, "NORTH");
  char* south = new char[6];
  strcpy(south, "SOUTH");
  char* east = new char[6];
  strcpy(east, "EAST");
  char* west = new char[6];
  strcpy(west, "WEST");
  char* up = new char[6];
  strcpy(up, "UP");
  char* down = new char[6];
  strcpy(down, "DOWN");


  //room vector
  vector<Room*>* rooms = new vector<Room*>;
  
  //descriptions & initialization for Rooms
  //rooms created left-right top-bottom according to map
  //note: char* will be deleted by Room destructors so do not reference elsewhere
  char* a = new char[256];
  strcpy(a, "You are in your apartment in Boston.");  
  Room* apartment = new Room(a);
  //apartment->printInfo();
  rooms->push_back(apartment);
  
  char* b = new char[256];
  strcpy(b, "You are in an Uber.");  
  Room* uber = new Room(b);
  //uber->printInfo();
  rooms->push_back(uber);
  
  //uber->addExit(south, apartment);
  
  char* c = new char[256];
  strcpy(c, "You are gazing up at the Washington Memorial. Are you going to ride the elevator to the top?");  
  Room* washMem = new Room(c);
  //washMem->printInfo();
  rooms->push_back(washMem);
  
  char* d = new char[256];
  strcpy(d, "You are looking out over Washington D.C. from the top of the Washington Memorial. Aren't you glad you came up here?");  
  Room* topWashMem = new Room(d);
  //topWashMem->printInfo();
  rooms->push_back(topWashMem);
  
  char* e = new char[256];
  strcpy(e, "You are in a busy subway station.");  
  Room* station = new Room(e);
  //station->printInfo();
  rooms->push_back(station);
  
  char* f = new char[256];
  strcpy(f, "You are standing in the conter of the National Mall in Washington, D.C.!");  
  Room* natlMall = new Room(f);
  //natlMall->printInfo();
  rooms->push_back(natlMall);
  
  char* g = new char[256];
  strcpy(g, "You are in a VERY crowded subway station in New York City.");  
  Room* subwayNYC = new Room(g);
  //subwayNYC->printInfo();
  rooms->push_back(subwayNYC);
  
  char* h = new char[256];
  strcpy(h, "You have boarded the subway. It's going to be a long trip no matter which direction you go.");  
  Room* train = new Room(h);
  //train->printInfo();
  rooms->push_back(train);
  
  char* i = new char[256];
  strcpy(i, "You are below ground at a subway station somewhere in Washington D.C., a long way from home!");  
  Room* subwayDC = new Room(i);
  //subwayDC->printInfo();
  rooms->push_back(subwayDC);
  
  char* j = new char[256];
  strcpy(j, "Wow! You are right in front of the White House lawn.");  
  Room* whiteHouse = new Room(j);
  //whiteHouse->printInfo();
  rooms->push_back(whiteHouse);
  
  char* k = new char[256];
  strcpy(k, "You have walked into the 1st floor of a large skyscraper.");  
  Room* skyOne = new Room(k);
  //skyOne->printInfo();
  rooms->push_back(skyOne);
  
  char* l = new char[256];
  strcpy(l, "Shh...walk quietly. It looks like you found a secret passageway under the city."); 
  Room* secretPass = new Room(l);
  //secretPass->printInfo();
  rooms->push_back(secretPass);
  
  char* m = new char[256];
  strcpy(m, "You're in a large cement room filled with boxes and office furniture. You realize you're in the basement of the Captial Building.");  
  Room* capital = new Room(m);
  //capital->printInfo();
  rooms->push_back(capital);
  
  char* n = new char[256];
  strcpy(n, "You are in a dark, cramped room. You switch on the light and realize you are surrounded by mops in a closet.");  
  Room* closet = new Room(n);
  //closet->printInfo();
  rooms->push_back(closet);
  
  char* o = new char[256];
  strcpy(o, "You have landed on the second floor of the skyscraper. Cubicles and conference rooms are full of busy people.");  
  Room* skyTwo = new Room(o);
  //skyTwo->printInfo();
  rooms->push_back(skyTwo);

  char* p = new char[256];
  strcpy(p, "You find yourself before a great door. You push it open and find yourself on the floor of the Senate.");  
  Room* senate = new Room(p);
  //  senate->printInfo();
  rooms->push_back(senate);

  //add exits for each room
  //added in order of left-right top-bottom according to map
  apartment->addExit(east, uber);

  uber->addExit(west, apartment);
  uber->addExit(south, station);

  washMem->addExit(up, topWashMem);
  washMem->addExit(south, natlMall);

  topWashMem->addExit(down, washMem);

  station->addExit(north, uber);
  station->addExit(south, train);

  natlMall->addExit(north, washMem);
  natlMall->addExit(south, whiteHouse);

  subwayNYC->addExit(east, train);
  subwayNYC->addExit(south, skyOne);

  train->addExit(north, station);
  train->addExit(east, subwayDC);
  train->addExit(west, subwayNYC);

  subwayDC->addExit(up, whiteHouse);
  subwayDC->addExit(west, train);

  whiteHouse->addExit(north, natlMall);
  whiteHouse->addExit(south, secretPass);
  whiteHouse->addExit(down, subwayDC);

  skyOne->addExit(north, subwayNYC);
  skyOne->addExit(up, skyTwo);

  secretPass->addExit(north, whiteHouse);
  secretPass->addExit(east, capital);

  capital->addExit(west, secretPass);
  capital->addExit(up, senate);

  closet->addExit(east, skyOne);

  skyTwo->addExit(down, skyOne);
  skyTwo->addExit(west, closet);

  senate->addExit(down, capital);


  //initialize and place 5 items
  //do not reference char* elsewhere, items will delete when they destruct
  char* gavelD = new char[10];
  strcpy(gavelD, "GAVEL");
  Item* gavel = new Item(gavelD);
  senate->addItem(gavel);

  char* mopD = new char[10];
  strcpy(mopD, "MOP");
  Item* mop = new Item(mopD);
  closet->addItem(mop);

  char* keychainD = new char[10];
  strcpy(keychainD, "KEYCHAIN");
  Item* keychain = new Item(keychainD);
  topWashMem->addItem(keychain);

  char* sandwichD = new char[10];
  strcpy(sandwichD, "SANDWICH");
  Item* sandwich = new Item(sandwichD);
  subwayNYC->addItem(sandwich);

  char* tulipD = new char[10];
  strcpy(tulipD, "TULIP");
  Item* tulip = new Item(tulipD);
  whiteHouse->addItem(tulip);

  for(vector<Room*>::iterator it = rooms->begin(); it != rooms->end(); ++it){
      (*it)->printInfo();
  }
  
  senate->dropItem(gavel);
  senate->printInfo();

  closet->addItem(gavel);
  closet->printInfo();

  char* input = new char[256];
  cin.get(input, 256);
  cin.get();
  char* str;
  //strcpy(str, input);
  cout << "Splitting cstring: " << endl;
  str = strtok(input, ".,!- ");
  while(str != NULL){
    cout << str << endl;
    str = strtok(NULL, ".,!- ");
  }

  delete [] north;
  delete [] south;
  delete [] west;
  delete [] east;
  delete gavel;
  delete mop;
  delete keychain;
  delete sandwich;
  delete tulip;
  return 0;
}
