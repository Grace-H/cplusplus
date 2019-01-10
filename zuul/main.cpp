/*
Zuul: A text-based adventure game set on the east coast
Objective: discover and drop all five items in appartment
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

  //GAVEL
  char* gavelD = new char[10];
  strcpy(gavelD, "GAVEL");
  Item* gavel = new Item(gavelD);
  senate->addItem(gavel);
  allItems->push_back(gavel);
  
  //MOP
  char* mopD = new char[10];
  strcpy(mopD, "MOP");
  Item* mop = new Item(mopD);
  closet->addItem(mop);
  allItems->push_back(mop);

  //KEYCHAIN
  char* keychainD = new char[10];
  strcpy(keychainD, "KEYCHAIN");
  Item* keychain = new Item(keychainD);
  topWashMem->addItem(keychain);
  allItems->push_back(keychain);
  
  //SANDWICH
  char* sandwichD = new char[10];
  strcpy(sandwichD, "SANDWICH");
  Item* sandwich = new Item(sandwichD);
  subwayNYC->addItem(sandwich);
  allItems->push_back(sandwich);
  
  //TULIP
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

  //introduce game
  printIntro();
  cout << endl;
  cRoom->printInfo();

  //input processing chars
  char* input = new char[256];
  char* str;
  
  //while game is being played
  while(running){  
    
    //read instruction
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
    if(strcmp(go, str) == 0){
      
      //get direction
      str = strtok(NULL, ".,!- ");
      
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
      //get item
      str = strtok(NULL, ".,!- ");
      //if second word was entered...
      if(str != NULL){
	//find item
	bool found = false;
	for(vector<Item*>::iterator it = allItems->begin(); it != allItems->end(); it++){
	  char* name = (*it)->getName();
	  if(strcmp(name, str) == 0){
	    getItem(inventory, (*it), cRoom); //pick up item if found
	    found = true;
	    break;
	  }
	}
	//if item doesn't exist
	if(!found){
	  cout << "There is no " << str << "." << endl;
	}
      }
      else{
	cout << "You want to do what?" << endl;
      }
    }
    
    //DROP
    else if(strcmp(str, drop) == 0){
      //find item user wants
      str = strtok(NULL, ".,!- ");
      //if another word was entered...
      if(str != NULL){
	bool found = false;
	for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); it++){
	  char* name = (*it)->getName();
	  if(strcmp(name, str) == 0){
	    //when item found, run drop function
	    dropItem(inventory, (*it), cRoom);
	    found = true;
	    break;
	  }
	}
	//if the user wasn't holding item
	if(!found){
	  cout << "You have no " << str << "." << endl;
	}
      }
      else{
	cout << "You want to do what?" << endl;
      }
    }
    
    //LOST/help
    else if(strcmp(str, lost) == 0){
      giveHelp();
    }
    
    else{
      cout << "You want to do what?" << endl;
    }

    //check if this move has caused win
    if(checkWin(apartment)){
      cout << "Congratulations! You got all the items to your apartment!" << endl;
      running = false;
    }
  }

  //delete pointers
  vector<Room*>::iterator it;
  while(!rooms->empty()){
    it = rooms->begin();
    //    (*it)->printInfo();
    rooms->erase(it);
  }
  delete rooms;

  delete [] input;
  delete [] north;
  delete [] south;
  delete [] west;
  delete [] east;
  delete [] down;
  delete [] up;
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
}

//cheks if there are five items in the apartment, returns true if yes
bool checkWin(Room* apartment){
  if(apartment->lenInventory() == 5){
    return true;
  }
  else{
    return false;
  }
}

//removes an items from player's inventory, adds to current Room
void dropItem(vector<Item*>* inventory, Item* item, Room* cRoom){
  //add item to current Room
  cRoom->addItem(item);
  //find item in player's inventory and erase
  bool found = false;
  for(vector<Item*>::iterator it = inventory->begin(); it != inventory->end(); it++){
    if((*it) == item){
      inventory->erase(it);
      found = true;
      break;
    }
  }
  //notify user whether action worked or not
  if(found){
    cout << "Dropped " << item->getName() << "." << endl;
  }
  else{
    cout << "You have no " << item->getName() << "." << endl;
  }
}

//removes Item from Room and adds to player's inventory
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

//print instructions for game
void giveHelp(){
  cout << "You are lost." << endl;
  cout << "Your goal is to collect all five items and drop them in your appartment." << endl;
  cout << "Your command words are: 'GO' 'HELP' 'GET' 'DROP' and 'QUIT'" << endl;
}

//changes current Room based on given direction
Room* changeRoom(Room* cRoom, char* direction){
  //find room atached to exit
  Room* newRoom = cRoom->getRoom(direction);
  //check if room actually exists at that exit
  if(newRoom != NULL){
    return newRoom;
  }
  else{
    cout << "Oops, can't go that way." << endl;
    return cRoom;
  }
}

//print openning instructions for the game
void printIntro(){  
  cout << "Welcome to Zuul, a text-based adventure game." << endl;
  cout << "Your goal: find and drop all five items in your apartment." << endl;
  cout << "If you are ever lost or need help, simply type 'LOST'" << endl;
  //cout << "Time starts on your first command." << endl;
}
