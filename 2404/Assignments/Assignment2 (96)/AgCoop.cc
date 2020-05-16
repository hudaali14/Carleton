#include <iostream>
using namespace std;
#include <string>

#include "AgCoop.h"

AgCoop::AgCoop(){
  size = 0;
  cout << "-- AgCoop ctor: "  << endl;
}

AgCoop::~AgCoop(){
  cout << "-- AgCoop dtor: "  << endl;
  for(int i = 0; i < size; i++){
    delete farmCollection[i];
  }
}

void AgCoop::add(Farm* f){
  if(size >= MAX_FARM){
    delete f;
    return;
  }
  farmCollection[size] = f;
  size++;
}

void AgCoop::add(int id, Animal* a){
  for(int i = 0; i < size; i++){
    if(id == farmCollection[i]->getId()){
      farmCollection[i]->add(a);
      return;
    }
  }
  delete a;
}

void AgCoop::print(){
  cout << endl << "FARMS: " << endl << endl;
  for(int i = 0; i < size; i++){
    farmCollection[i]->print();
  }
}
