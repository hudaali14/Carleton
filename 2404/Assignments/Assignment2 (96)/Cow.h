#ifndef COW_H
#define COW_H

#include "Animal.h"

/*

PURPOSE: Cow class as derived from Animal with name, age, lifespan, and milk time

*/

class Cow : public Animal
{
  public:
    Cow(string="Little Red Hen", int=0, float=0, string="00:00");
    ~Cow();
    virtual void print() const;

  private:
    string milk;
};

#endif
