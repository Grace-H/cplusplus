/*
Zuul: A text-based adventure game set on the east coast
Objective: discover and collect all five items in under 3 minutes
Author: Grace Hunter
Date: 16 November 2018
*/

#include <iostream>
#include <cstring>
#include "Item.h"
#include "room.h"

int main(){
  //descriptions & initialization for Rooms
  //rooms created left-right top-bottom according to map
  //note: char* will be deleted by Room destructors so do not reference elsewhere
  char* a = new char[256];
  strcpy(a, "You are in your apartment in Boston.");  
  Room* apartment = new Room(a);
  apartment->printInfo();
  
  char* b = new char[256];
  strcpy(b, "You are in an Uber.");  
  Room* uber = new Room(b);
  uber->printInfo();

  char* c = new char[256];
  strcpy(c, "You are gazing up at the Washington Memorial. Are you going to ride the elevator to the top?");  
  Room* washMem = new Room(c);
  washMem->printInfo();

  char* d = new char[256];
  strcpy(d, "You are looking out over Washington D.C. from the top of the Washington Memorial. Aren't you glad you came up here?");  
  Room* topWashMem = new Room(d);
  topWashMem->printInfo();

  char* e = new char[256];
  strcpy(e, "You are in a busy subway station.");  
  Room* station = new Room(e);
  station->printInfo();

  char* f = new char[256];
  strcpy(f, "You are standing in the conter of the National Mall in Washington, D.C.!");  
  Room* natlMall = new Room(f);
  natlMall->printInfo();

  char* g = new char[256];
  strcpy(g, "You are in a VERY crowded subway station in New York City.");  
  Room* stationNYC = new Room(g);
  stationNYC->printInfo();

//cout << "Hello World!" << endl;
  //char libraryD = "Hello world";
  //cout << libraryD << endl;  
  //char labD[256] = "hello world";
  
  //Room* lab = new Room(labD);
//char* east = new char[5];
  //strcpy(east, "EAST");
  //  library->addExit(east, lab);
  
  //delete lab;
  //delete library;
  return 0;
}
