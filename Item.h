#ifndef ALPHA
#define ALPHA

#include<iostream>
#include<cstring>

using namespace std;

class Item {
public:
  Item(char* name);
  char* getName();
protected:
  char* name;
  
};

#endif // ALPHA
