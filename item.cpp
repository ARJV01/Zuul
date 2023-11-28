#include<iostream>
#include<cstring>
#include"Item.h"

using namespace std;

Item :: Item(char* title) {//contructor for items
  name = new char[80];
  strcpy(name, title);

}

char* Item :: getName() {//gettter for names
  return name;
}
