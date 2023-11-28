#include<iostream>
#include<cstring>
#include"Room.h"

using namespace std;

Room :: Room(char* name) {//room contrucotr
  title = new char[80];
  strcpy(title, name);
}

char* Room :: getName() {//getter for name
  return title;
}
