#ifndef BRAVO
#define BRAVO

#include<iostream>
#include<cstring>

using namespace std;

class Item {
public:
  Item(char* name);//contructor for item
  char* getName();//getter for name
protected:
  char* name;
  
};

#endif // BRAVO
