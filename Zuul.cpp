#include<iostream>
#include<cstring>
#include<vector>
#include"Room.h"
#include"Item.h"
#include<map>

using namespace std;

class Exit {
public:
  bool north;
  bool east;
  bool south;
  bool west;
  Room* westRoom;
  Room* eastRoom;
  Room* northRoom;
  Room* southRoom;
};

void createRoom(vector<Room*> &roomLs, map<Room*, Exit> &gameMap );
void move(vector<Room*> roomLs, map<Room*, Exit> gameMap );

int main() {
  vector<Room*> roomLs;
  map<Room*, Exit> gameMap;
  createRoom(roomLs, gameMap);
  move(roomLs, gameMap);
  

  return 0;
}

void createRoom(vector<Room*> &roomLs,map<Room*, Exit> &gameMap) {
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

   roomLs.push_back(room1);
   roomLs.push_back(room2);
   roomLs.push_back(room3);
   roomLs.push_back(room4);
   roomLs.push_back(room5);
   roomLs.push_back(room6);
   roomLs.push_back(room7);
   roomLs.push_back(room8);
   roomLs.push_back(room9);
   roomLs.push_back(room10);
   roomLs.push_back(room11);
   roomLs.push_back(room12);
   roomLs.push_back(room13);
   roomLs.push_back(room14);
   roomLs.push_back(room15);

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
   gameMap.insert({room1,exit2});



}

void move(vector<Room*> roomLs, map<Room*, Exit> gameMap ) {
  Room* location = roomLs[0];
  bool playing = true;
  while(playing == true) {
    cout << location -> getName() << endl;
    
  }
}


