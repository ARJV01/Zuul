#ifndef ALPHA
#define ALPHA

#include<iostream>
#include<cstring>

using namespace std;

class Room {
public:
  Room(char* name);
  char* getName();

protected:
  char* title;

};

#endif // ALPHA

