#include <iostream>
using namespace std;
#include <string>

#include "Pig.h"

Pig::Pig(string n, int a, float l, int p) : pens(p), Animal(n,a,l)
{
  cout << "-- Cow ctor: " << getName() << endl;
}

Pig::~Pig()
{
  cout << "-- Cow dtor: " << getName() << endl;
}

void Pig::print()
{
  Animal::print();
  cout << " and I'm a cow that can produce " << pens << " eggs weekly" << endl;
}