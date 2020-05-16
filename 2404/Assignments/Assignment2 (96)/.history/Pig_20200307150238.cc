#include <iostream>
using namespace std;
#include <string>

#include "Pig.h"

Pig::Pig(string n, int a, float l, int p) : pens(p), Animal(n,a,l)
{
  cout << "-- Pig ctor: " << getName() << endl;
}

Pig::~Pig()
{
  cout << "-- Pig dtor: " << getName() << endl;
}

void Pig::print()
{
  Animal::print();
  cout << " and I'm a pig and I live in " << pens << " eggs weekly" << endl;
}