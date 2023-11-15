#include<iostream>
#include<cstring>
#include"Room.h"

using namespace std;

Room :: Room(char* name) {
  title = new char[80];
  strcpy(title, name);
}

char* Room :: getName() {
  return title;
}
