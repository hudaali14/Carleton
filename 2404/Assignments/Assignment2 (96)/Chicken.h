#ifndef CHICKEN_H
#define CHICKEN_H

#include "Animal.h"

/*
CHICKEN CLASS
PURPOSE:  Chicken class as derived from Animal with name, age, lifespan, and egg count

*/

class Chicken : public Animal
{
  public:
    Chicken(string="Little Red Hen", int=0, float=0, int=0);
    ~Chicken();
    virtual void print() const;

  private:
    int eggCount;
};

#endif
