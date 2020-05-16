#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal
{
  public:
    Cow(string="Little Red Hen", int=0, float=0, string="00:00");
    ~Cow();
    void print();

  private:
    int milk;
};

#endif