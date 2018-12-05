/*
Zuul: A text-based adventure game set on the east coast
Objective: discover and collect all five items in under 3 minutes
Author: Grace Hunter
Date: 16 November 2018
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <typeinfo>
#include "Item.h"
#include "Room.h"

void printIntro();
bool checkWin(Room* apartment);
void getItem(vector<Item*>* inventory, Item* item, Room* cRoom);
void dropItem(vector<Item*>* inventory, Item* item, Room* cRoom);
void giveHelp();
Room* changeRoom(Room* cRoom, char* direction);

int main(){
  
  //GAME SETUP

  //direction char arrays, used for creating exits and moving
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

  //command char arrays, used by user
  char* go = new char[6];
  strcpy(go, "GO");
  char* drop = new char[6];
  strcpy(drop, "DROP");
  char* get = new char[6];
  strcpy(get, "GET");
  char* lost = new char[6];
  strcpy(lost, "LOST");
  char* quit = new char[6];
  strcpy(quit, "QUIT");
  
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
  strcpy(f, "You are standing in the center of the National Mall, the huge greenspace in the middle of D.C.");  
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

  closet->addExit(east, skyTwo);

  skyTwo->addExit(down, skyOne);
  skyTwo->addExit(west, closet);

  senate->addExit(down, capital);

  //initialize and place 5 items
  //do not reference char* elsewhere, items will delete when they destruct
  vector<Item*>* allItems = new vector<Item*>; //vector of all items

  char* gavelD = new char[10];
  strcpy(gavelD, "GAVEL");
  Item* gavel = new Item(gavelD);
  senate->addItem(gavel);
  allItems->push_back(gavel);
  
  char* mopD = new char[10];
  strcpy(mopD, "MOP");
  Item* mop = new Item(mopD);
  closet->addItem(mop);
  allItems->push_back(mop);

  char* keychainD = new char[10];
  strcpy(keychainD, "KEYCHAIN");
  Item* keychain = new Item(keychainD);
  topWashMem->addItem(keychain);
  allItems->push_back(keychain);
  
  char* sandwichD = new char[10];
  strcpy(sandwichD, "SANDWICH");
  Item* sandwich = new Item(sandwichD);
  subwayNYC->addItem(sandwich);
  allItems->push_back(sandwich);
  
  char* tulipD = new char[10];
  strcpy(tulipD, "TULIP");
  Item* tulip = new Item(tulipD);
  whiteHouse->addItem(tulip);
  allItems->push_back(tulip);
  
  //GAME PLAY

  //  bool timing = false; //whether timer is running
  bool running = true; //whether game is running
  Room* cRoom = apartment; //current room
  vector<Item*>* inventory = new vector<Item*>; //player's inventory of items they're holding

  printIntro();
  cout << endl;
  cRoom->printInfo();

  char* input = new char[256];
  char* str;
  
  while(running){  
    //    cout << "252" << endl;
    cin.get(input, 256);
    cin.get();

    //make input all caps
    for(int i = 0; i < strlen(input); i++){
      input[i] = toupper(input[i]);
    }
    
    //get first word
    str = strtok(input, ".,!- ");
    //identify first command
    //GO
    //cout << "265" << endl;
    if(strcmp(go, str) == 0){
      cout << "You entered 'go'" << endl;
      //get direction
      str = strtok(NULL, ".,!- ");
      //cout << "You want to go " << str << endl;
      //EAST
      if(str != NULL){
	if(strcmp(str, east) == 0){
	  cRoom = changeRoom(cRoom, east);
	}
	//WEST
	else if(strcmp(str, west) == 0){
	cRoom = changeRoom(cRoom, west);
	}
	//NORTH
	else if(strcmp(str, north) == 0){
	  cRoom = changeRoom(cRoom, north);
	}
	//SOUTH      
	else if(strcmp(str, south) == 0){
	  cRoom = changeRoom(cRoom, south);
	}
	//UP
	else if(strcmp(str, up) == 0){
	  cRoom = changeRoom(cRoom, up);
	}
	//DOWN
	else if(strcmp(str, down) == 0){
	  cRoom = changeRoom(cRoom, down);
	}
	//DNE
	else{
	  cout << "Oops, can't go there." << endl;
	}
	cout << endl;
	//print info of now-current room
	cRoom->printInfo();
      }
      else{
	cout << "You want to do what?" << endl;
      }  
    }

    //QUIT
    else if(strcmp(str, quit) == 0){
      running = false;
    }

    //GET
    else if(strcmp(str, get) == 0){
      //cout << "308" << endl;
      str = strtok(NULL, ".,!- ");
      if(str != NULL){
	bool found = false;
	for(vector<Item*>::iterator it = allItems->begin(); it != allItems->end(); it++){
	  char* name = (*it)->getName();
	  //cout << name << endl;
	  if(strcmp(name, str) == 0){
	    //cout << "You found the item!" << endl;
	    getItem(inventory, (*it), cRoom);
	    //cout << "line before" << endl;
	    found = true;
	    break;
	    //cout << "line after" << endl;
	  }
	}
	if(!found){
	  cout << "There is no " << str << "." << endl;
	}
	//cout << "324" << endl;
      }
      else{
	cout << "You want to do what?" << endl;
      }
    }
    
    //DROP
    else if(strcmp(str, drop) == 0){
      str = strtok(NULL, ".,!- ");
      bool found = false;
      for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); it++){
	char* name = (*it)->getName();
	//cout << name << endl;
	if(strcmp(name, str) == 0){
	  //cout << "You found the item!" << endl;
	  dropItem(inventory, (*it), cRoom);
	  //it = inventory->end();
	  found = true;
	  break;
	}
      }
      if(!found){
	cout << "You have no " << str << "." << endl;
      }
      //cout << "339" << endl;
    }
    
    //LOST/help
    else if(strcmp(str, lost) == 0){
      giveHelp();
      //cout << "339" << endl;
    }
    
    else{
      cout << "You want to do what?" << endl;
    }

    //check if this move has caused win
    if(checkWin(apartment)){
      cout << "Congratulations! You got all the items to your apartment!" << endl;
      running = false;
    }
    //cout << "347" << endl;
  }

  delete [] input;
  delete [] str;
  delete [] north;
  delete [] south;
  delete [] west;
  delete [] east;
  delete [] go;
  delete [] drop;
  delete [] lost;
  delete [] get;
  delete [] quit;
  delete gavel;
  delete mop;
  delete keychain;
  delete sandwich;
  delete tulip;
  return 0;

  //playGame();
}


bool checkWin(Room* apartment){
  if(apartment->lenInventory() == 5){
    return true;
  }
  else{
    return false;
  }
}

void dropItem(vector<Item*>* inventory, Item* item, Room* cRoom){
  //inventory->erase(item);
  //  cout << typeid(item).name() << endl;
  cRoom->addItem(item);
  bool found = false;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); it++){
    if((*it) == item){
      inventory->erase(it);
      //it = inventory->end();
      found = true;
      break;
    }
  }
  if(found){
    cout << "Dropped " << item->getName() << "." << endl;
  }
  else{
    cout << "You have no " << item->getName() << "." << endl;
  }
}

void getItem(vector<Item*>* inventory, Item* item, Room* cRoom){
  if(cRoom->hasItem(item)){
    inventory->push_back(item);
    cRoom->dropItem(item);
    cout << "Got " << item->getName() << endl;
  }
  else{
    cout << "There is no " << item->getName() << "." << endl;
  }
}

void giveHelp(){
  cout << "You are lost." << endl;
  cout << "Your goal is to collect all five items in 3 minutes and take them to your appartment." << endl;
  cout << "Your command words are: 'GO' 'HELP' 'GET' 'DROP' and 'QUIT'" << endl;
}

Room* changeRoom(Room* cRoom, char* direction){
  Room* newRoom = cRoom->getRoom(direction);
  //cout << "this is the room" << endl;
  //newRoom->printInfo();
  if(newRoom != NULL){
    return newRoom;
    //cRoom->printInfo();
  }
  else{
    cout << "Oops, can't go that way." << endl;
    return cRoom;
  }
}

void printIntro(){  
  cout << "Welcome to Zuul, a text-based adventure game." << endl;
  cout << "Your goal: find and move all five items to your apartment." << endl;
  cout << "If you are ever lost or need help, simply type 'LOST'" << endl;
  //cout << "Time starts on your first command." << endl;
}
