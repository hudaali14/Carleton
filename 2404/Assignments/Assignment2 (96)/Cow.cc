#include <iostream>
using namespace std;
#include <string>

#include "Cow.h"

Cow::Cow(string n, int a, float l, string m) : milk(m), Animal(n,a,l)
{
  cout << "------ Cow ctor: " << getName() << endl;
}

Cow::~Cow()
{
  cout << "------ Cow dtor: " << getName() << endl;
}

void Cow::print() const
{
  Animal::print();
  cout << "     and I'm a cow that gets milked at " << milk << endl;
}
