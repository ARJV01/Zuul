#include<iostream>
#include<cstring>
#include"Item.h"

using namespace std;

Item :: Item(char* name) {
  name = new char[80];
  strcpy(name, name);

}

char* Item :: getName() {
  return Item;
}
