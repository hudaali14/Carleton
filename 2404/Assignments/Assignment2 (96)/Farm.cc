#include <iostream>
using namespace std;
#include <string>

#include "Farm.h"

int Farm::nextId = 1001;

Farm::Farm(){
  id = nextId;
  ++nextId;
  cout << "--- Farm ctor: "  << endl;
}

Farm::~Farm(){
  cout << "--- Farm dtor: "  << endl;
}

int Farm::getId() { return id; }

void Farm::add(Animal* a){
  animalList.List::add(a);
}

void Farm::print(){
  cout << "Farm id: "<< id << endl;
  animalList.List::print();
  cout << endl;
}
