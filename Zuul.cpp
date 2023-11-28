#include<iostream>
#include<cstring>
#include<vector>
#include"Room.h"
#include"Item.h"
#include<map>

//Arjun Vinsel
//11/28/23
//This program is a text based game. Players con move pick up or drop items. To win they must reach pizza land.

using namespace std;

class Exit {//Sets the exits of a room and the rooms they correspond to
public:
  bool north;
  bool east;
  bool south;
  bool west;
  Room* westRoom;
  Room* eastRoom;
  Room* northRoom;
  Room* southRoom;
  void printExits() {//prints the exits of a room
    if(north == true) {
      cout<<"There is: " << northRoom -> getName() << " to the north" << endl;
    }
    if(east == true) {
      cout << "There is: " << eastRoom -> getName() << " to the east" << endl;
    }
    if(south == true) {
      cout <<"There is: " << southRoom -> getName() << " to the south" << endl;
    }
    if(west == true) {
      cout << "There is: " << westRoom -> getName() << " to the west" << endl;
    }
  }
};

void createRoom(vector<Room*> &roomLs, map<Room*, Exit> &gameMap,map<Item*, Room*> &itemMap);//creats rooms and items in the room
void move1(vector<Room*> roomLs, map<Room*, Exit> gameMap,Room* &location);//responsible for playermovemnt
void drop(vector<Item*> &inventory, vector<Room*> roomLs, map<Room*, Exit> gameMap,map<Item*, Room*> &itemMap,Room* location);//repsonible for when a player wants to drop and item
void pick(vector<Item*> &inventory, vector<Room*> roomLs, map<Room*, Exit> gameMap,map<Item*, Room*> &itemMap,Room* location);//responsible for when a player wants to pick up an item

int main() {//main class
  bool stillPlaying = true;
  vector<Room*> roomLs;
  map<Room*, Exit> gameMap;
  map<Item*, Room*> itemMap;
  createRoom(roomLs, gameMap, itemMap);
 Room* location = roomLs[0];
  char move[80];
  char input[80];
  vector<Item*> inventory;
  cout << "Reach Pizza Land" << endl;
  while(stillPlaying == true) {
  cout << "you are in: " << location -> getName() << endl;
  for(auto i = itemMap.begin(); i != itemMap.end(); i++) {
           if(i->second == location) {
             cout<< "There are the follwing in the room: " << ((i -> first)->getName()) << endl;
           }
        }
    for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
      if(i->first == location) {
        (i -> second).printExits();
      }
    }
        cout << "please enter move, drop pick or quit" << endl;
        cin >> input;
        cin.ignore(256 , '\n');
	if(strcmp(input , "move") == 0) {
	    move1(roomLs, gameMap,location);
	}
	else if(strcmp(input , "pick") ==0) {
	  pick(inventory, roomLs, gameMap, itemMap,location);
	  }
	else if (strcmp(input , "drop") == 0) {
	  drop(inventory, roomLs,gameMap,itemMap,location);
	      }
	else if(strcmp(input , "quit") == 0) {
	  stillPlaying = false;
	}
	else {
	  cout << "enter a valid move" << endl;
	}
	if(strcmp(location -> getName(), "pizzaland") == 0) {
	  cout << "you have reached Pizza land!" << endl;
	  stillPlaying = false;
	}
    
  }
  return 0;
}

void createRoom(vector<Room*> &roomLs,map<Room*, Exit> &gameMap,map<Item*, Room*> &itemMap) {// creates the rooms and items in them
 char* title1;
  title1 = new char [80];
  strcpy(title1, "pentagon");
 char* title2;
  title2 = new char [80];
  strcpy(title2, "tacobell");
 char* title3;
  title3 = new char [80];
  strcpy(title3, "czechoslovakia");
 char* title4;
  title4 = new char [80];
  strcpy(title4, "hogwarts");
 char* title5;
  title5 = new char [80];
   strcpy(title5, "berlin");
 char* title6;
  title6 = new char [80];
   strcpy(title6, "montelupo");
 char* title7;
  title7 = new char [80];
   strcpy(title7, "dulles");
 char* title8;
  title8 = new char [80];
   strcpy(title8, "chicago");
 char* title9;
  title9 = new char [80];
   strcpy(title9, "cybertron");
 char* title10;
  title10 = new char [80];
   strcpy(title10, "poland");
 char* title11;
  title11 = new char [80];
   strcpy(title11, "tokyo");
 char* title12;
  title12 = new char [80];
   strcpy(title12, "pizzacato");
 char* title13;
  title13 = new char [80];
  strcpy(title13, "ukraine");
 char* title14;
  title14 = new char [80];
   strcpy(title14, "beoing");
 char* title15;
  title15 = new char [80];
   strcpy(title15, "pizzaland");

   char* title16;
  title16 = new char [80];
   strcpy(title16, "none");


   Room *room1 = new Room(title1);
   Room *room2 = new Room(title2);
   Room *room3 = new Room(title3);
   Room *room4 = new Room(title4);
   Room *room5 = new Room(title5);
   Room *room6 = new Room(title6);
   Room *room7 = new Room(title7);
   Room *room8 = new Room(title8);
   Room *room9 = new Room(title9);
   Room *room10 = new Room(title10);
   Room *room11 = new Room(title11);
   Room *room12 = new Room(title12);
   Room *room13 = new Room(title13);
   Room *room14 = new Room(title14);
   Room *room15 = new Room(title15);
   Room *room16 = new Room(title16);

   roomLs.push_back(room1);//pentagon
   roomLs.push_back(room2);//taco bell
   roomLs.push_back(room3);//czechoslovakia
   roomLs.push_back(room4);//hogwarts
   roomLs.push_back(room5);//berlin
   roomLs.push_back(room6);//montelupo
   roomLs.push_back(room7);//dulles
   roomLs.push_back(room8);//chicago
   roomLs.push_back(room9);//cybertron
   roomLs.push_back(room10);//poland
   roomLs.push_back(room11);//tokyo
   roomLs.push_back(room12);//pizzacato
   roomLs.push_back(room13);//ukraine
   roomLs.push_back(room14);//beoing
   roomLs.push_back(room15);//pizzaland
   roomLs.push_back(room16);//none


   Exit exit1;
   exit1.north = true;
   exit1.east = true;
   exit1.south = true;
   exit1.west = false;
   exit1.northRoom = room2;
   exit1.eastRoom = room7;
   exit1.southRoom = room10;
   gameMap.insert({room1,exit1});

   Exit exit2;
   exit2.north = true;
   exit2.east = false;
   exit2.south = true;
   exit2.west = true;
   exit2.northRoom = room4;
   exit2.westRoom = room3;
   exit2.southRoom = room1;
   gameMap.insert({room2,exit2});

   Exit exit3;
   exit3.north = false;
   exit3.east = true;
   exit3.south = true;
   exit3.west = false;
   exit3.southRoom = room9;
   exit3.eastRoom = room2;
   gameMap.insert({room3,exit3});

   Exit exit4;
   exit4.north = false;
   exit4.east = false;
   exit4.south = true;
   exit4.west = false;
   exit4.southRoom = room2;
   gameMap.insert({room4,exit4});

   Exit exit5;
   exit5.north = false;
   exit5.east = true;
   exit5.south = true;
   exit5.west = false;
   exit5.southRoom = room7;
   exit5.eastRoom = room6;
   gameMap.insert({room5,exit5});

   Exit exit6;
   exit6.north = false;
   exit6.east = false;
   exit6.south = false;
   exit6.west = true;
   exit6.westRoom = room5;
   gameMap.insert({room6,exit6});

   Exit exit7;
   exit7.north = true;
   exit7.east = true;
   exit7.south = true;
   exit7.west = true;
   exit7.southRoom = room11;
   exit7.eastRoom = room8;
   exit7.westRoom = room1;
   exit7.northRoom = room5;
   gameMap.insert({room7,exit7});

   Exit exit8;
   exit8.north = false;
   exit8.east = false;
   exit8.south = true;
   exit8.west = true;
   exit8.southRoom = room15;
   exit8.westRoom = room7;
   gameMap.insert({room8,exit8});

   Exit exit9;
   exit9.north = true;
   exit9.east = false;
   exit9.south = true;
   exit9.west = false;
   exit9.southRoom = room9;
   exit9.eastRoom = room12;
   gameMap.insert({room9,exit9});

   Exit exit10;
   exit10.north = true;
   exit10.east = true;
   exit10.south = true;
   exit10.west = false;
   exit10.northRoom = room1;
   exit10.southRoom = room13;
   exit10.eastRoom = room11;
   gameMap.insert({room10,exit10});

   Exit exit11;
   exit11.north = true;
   exit11.east = false;
   exit11.south = true;
   exit11.west = true;
   exit11.northRoom = room7;
   exit11.southRoom = room14;
   exit11.westRoom = room10;
   gameMap.insert({room11,exit11});

   Exit exit12;
   exit12.north = true;
   exit12.east = true;
   exit12.south = false;
   exit12.west = false;
   exit12.northRoom = room9;
   exit12.eastRoom = room13;
   gameMap.insert({room12,exit12});

   Exit exit13;
   exit13.north = true;
   exit13.east = true;
   exit13.south = false;
   exit13.west = true;
   exit13.northRoom = room10;
   exit13.eastRoom = room14;
   exit13.westRoom = room12;
   gameMap.insert({room13,exit13});

   Exit exit14;
   exit14.north = true;
   exit14.east = true;
   exit14.south = false;
   exit14.west = true;
   exit14.northRoom = room11;
   exit14.eastRoom = room15;
   exit14.westRoom = room13;
   gameMap.insert({room14,exit14});

   Exit exit15;
   exit15.north = true;
   exit15.east = false;
   exit15.south = false;
   exit15.west = true;
   exit15.northRoom = room9;
   exit15.eastRoom = room13;
   gameMap.insert({room15,exit15});



   
   char* item1;
   item1 = new char[80];
   strcpy(item1, "computer");
   Item* computer = new Item(item1);
   itemMap.insert({computer,room1});

   char* item2;
   item2 = new char[80];
   strcpy(item2, "wall");
   Item* wall = new Item(item2);
   itemMap.insert({wall,room5});

   char* item3;
   item3 = new char[80];
   strcpy(item3, "fish");
   Item* fish = new Item(item3);
   itemMap.insert({fish,room11});

   char* item4;
   item4 = new char[80];
   strcpy(item4, "plane");
   Item* plane = new Item(item4);
   itemMap.insert({plane,room7});

   char* item5;
   item5 = new char[80];
   strcpy(item5, "pasta");
   Item* pasta = new Item(item5);
   itemMap.insert({pasta,room6});



}

void move1(vector<Room*> roomLs, map<Room*, Exit> gameMap,Room* &location) {//repsonible for player movement
  char* move;
  move = new char[80];
	cout << "Where do you wish to go" << endl;
for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
      if(i->first == location) {
	cin >> move;
	cin.ignore(256,'\n');
	if(strcmp(move, "north") == 0 && (i->second).north ==true) {
	    location = (i -> second).northRoom;
	    break;
	  }
	else if(strcmp(move, "east") == 0&& (i->second).east ==true) {
            location = (i -> second).eastRoom;
	    break;
          }
	else if(strcmp(move, "south") == 0&& (i->second).south ==true) {
            location = (i -> second).southRoom;
	    break;
          }
	else if(strcmp(move, "west") == 0&& (i->second).west ==true) {
            location = (i -> second).westRoom;
	    break;
          }
	else {
	  cout << "enter valid move" << endl;
	}
      }
      }
}
      
      
	      
void drop(vector<Item*> &inventory, vector<Room*> roomLs, map<Room*, Exit> gameMap,map<Item*, Room*> &itemMap,Room* location) {//when a player wants to drop an item
	char input[80];
	vector<Item*>:: iterator itr;
	for(itr = inventory.begin(); itr < inventory.end(); itr++) {
	  cout << (*itr) -> getName() << endl;
	}
	cout << "enter what do you wish to drop" << endl;
	cin >> input;
	cin.ignore(256, '\n');
	 for(auto i = itemMap.begin(); i != itemMap.end(); i++) {
	   if(strcmp(input, (i -> first) -> getName())  == 0) {
	     for(itr = inventory.begin(); itr< inventory.end(); itr++) {
	       if (strcmp(((*itr) -> getName()), ((i -> first) -> getName())) == 0) {
		   inventory.erase(itr);
		   (i -> second) = location;
		   break;
	       }
	     }
	     break;
	     }
	 }
      }
void pick(vector<Item*> &inventory, vector<Room*> roomLs, map<Room*, Exit> gameMap,map<Item*, Room*> &itemMap,Room* location) {//when a player wants to pick up an item
	char input[80];
        cout << "enter what do you wish to pick" << endl;
        cin >> input;
        cin.ignore(256, '\n');
         for(auto i = itemMap.begin(); i != itemMap.end(); i++) {
           if(strcmp(input, (i -> first) -> getName())  == 0 && strcmp((location -> getName()) , ((i->second) -> getName())) == 0) {
               inventory.push_back(i -> first);
	       i -> second = NULL;
	       
	       break;
             }
         }
	}
    



