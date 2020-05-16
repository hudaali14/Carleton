#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal
{
  public:
    Cow(string="00:00", int=0, float=0, int=0);
    ~Cow();
    void print();

  private:
    int eggCount;
};

#endif