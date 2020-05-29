#ifndef AGCOOP_H
#define AGCOOP_H

#define MAX_FARM 32

#include "Farm.h"

/*

AGCOOP CLASS
PURPOSE: Manages a collection of farms
COMPLEX OR CRITICAL MEMBERS:
  - Collection of farm
  - Function add(Farm*): Adds the given farm f to the back (the end) of the
farm array
  - Function add(int, Animal*): Adds the given animal a to the farm with
the unique identifier matching the parameter id

*/

class AgCoop
{
  public:
    AgCoop();
    ~AgCoop();
    void add(Farm* farm);
    void add(int farmId, Animal* animal);
    void print();

  private:
    Farm* farmCollection[MAX_FARM];
    int numFarms;
};

#endif
