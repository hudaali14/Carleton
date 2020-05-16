#ifndef PIG_H
#define PIG_H

#include "Animal.h"

/*
PIG CLASS
PURPOSE: Pig class as derived from Animal with name, age, lifespan, and pen number

*/

class Pig : public Animal
{
  public:
    Pig(string="Little Red Hen", int=0, float=0, int=0);
    ~Pig();
    virtual void print() const;

  private:
    int pens;
};

#endif
