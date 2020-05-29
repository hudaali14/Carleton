#include <iostream>
using namespace std;
#include <string>

#include "Chicken.h"

Chicken::Chicken(string n, int a, int l, int e) : eggCount(e), Animal(n,a,l)
{

}

Chicken::~Chicken()
{
}

void Chicken::print() const
{
  Animal::print();
  cout << "     and I'm a chicken that can produce " << eggCount << " eggs weekly" << endl;
}
