#ifndef FARM_H
#define FARM_H

#include "Animal.h"

class Farm : public Animal
{
  public:
    Farm(string="Little Red Hen", int=0, float=0, int=0);
    ~Farm();
    void print();

  private:
    int pens;
};

#endif