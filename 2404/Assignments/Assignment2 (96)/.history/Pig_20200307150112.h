#ifndef PIG_H
#define PIG_H

#include "Animal.h"

class Pig : public Animal
{
  public:
    Pig(string="Little Red Hen", int=0, float=0, int=0);
    ~Pig();
    void print();

  private:
    int pens;
};

#endif