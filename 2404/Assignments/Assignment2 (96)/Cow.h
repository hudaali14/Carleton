#ifndef COW_H
#define COW_H

#include "Animal.h"

/*

PURPOSE: Cow class as derived from Animal with name, age, lifespan, and milk time

*/

class Cow : public Animal
{
  public:
    Cow(string="", int=0, int=0, string="");
    ~Cow();
    virtual void print() const;

  private:
    string milkTime;
};

#endif
