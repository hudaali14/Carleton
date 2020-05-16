#include <iostream>
using namespace std;
#include <string>

#include "Cow.h"

Cow::Cow(string n, int a, float l, string m) : milk(m), Animal(n,a,l)
{
  cout << "-- Cow ctor: " << getName() << endl;
}

Cow::~Cow()
{
  cout << "-- Cow dtor: " << getName() << endl;
}

void Cow::print()
{
  Animal::print();
  cout << " and I'm a cow that can produce " << milk << " eggs weekly" << endl;
}