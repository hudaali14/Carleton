#include <iostream>
using namespace std;
#include <string>

#include "Farm.h"

int Farm::nextId = 1001;

Farm::Farm(){
  id = nextId;
  ++nextId;
}

Farm::~Farm(){
}

int Farm::getId() { return id; }

void Farm::add(Animal* animal){
  animalList.add(animal);
}

void Farm::print(){
  cout << "Farm id: "<< id << endl;
  animalList.print();
  cout << endl;
}
