#ifndef ALPHA
#define ALPHA

#include<iostream>
#include<cstring>

using namespace std;

class Room {
public:
  Room(char* name);//room constructor
  char* getName();//getter for names

protected:
  char* title;

};

#endif // ALPHA

