#include <iostream>
using namespace std;
#include <string>

#include "Chicken.h"

Chicken::Chicken(string n, int a, float l, int e) : eggCount(e), Animal(n,a,l)
{
  cout << "------ Chicken ctor: " << getName() << endl;

}

Chicken::~Chicken()
{
  cout << "------ Chicken dtor: " << getName() << endl;
}

void Chicken::print() const
{
  Animal::print();
  cout << "     and I'm a chicken that can produce " << eggCount << " eggs weekly" << endl;
}
