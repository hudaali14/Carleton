#include <iostream>
using namespace std;
#include <string>

#include "AgCoop.h"

AgCoop::AgCoop(){
  numFarms = 0;
}

AgCoop::~AgCoop(){
  for(int i = 0; i < numFarms; i++){
    delete farmCollection[i];
  }
}

// Adds given farm to back of array
void AgCoop::add(Farm* farm){
  // If array is already full, deallocates memory
  if(numFarms >= MAX_FARM){
    delete farm;
    return;
  }

  // Adds farm to end of array and increases size
  farmCollection[numFarms] = farm;
  numFarms++;
}

// Adds given animal to the farm with the unique identifier matching farmId
void AgCoop::add(int farmId, Animal* animal){

  for(int i = 0; i < numFarms; i++){
    // If farm is found that matches id, add animal to that farm
    if(farmId == farmCollection[i]->getId()){
      farmCollection[i]->add(animal);
      return;
    }
  }

  //If farm with the unique identifier wasn't found, deallocate memory
  delete animal;
}

void AgCoop::print(){
  cout << endl << "FARMS: " << endl << endl;
  for(int i = 0; i < numFarms; i++){
    farmCollection[i]->print();
  }
}
