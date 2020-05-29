#ifndef FARM_H
#define FARM_H

#include "Animal.h"
#include "List.h"

/*

FARM CLASS
PURPOSE: Manages a collection of animals
COMPLEX OR CRITICAL MEMBERS:
  - Singly linked list
  - Static int to store the identifier of the next farm to be created
  - Function add(Animal*):  Adds the given animal a to the linked list, in
descending order by age

*/

class Farm
{
  public:
    Farm();
    ~Farm();
    int getId();
    void add(Animal* animal);
    void print();

  private:
    static int nextId;
    int id;
    List animalList;
};

#endif
