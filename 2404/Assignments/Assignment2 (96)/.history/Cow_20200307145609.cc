#include <iostream>
using namespace std;
#include <string>

#include "Cow.h"

Cow::Cow(string n, int a, float l, string m) : milk(m), Animal(n,a,l)
{
  cout << "-- Chicken ctor: " << getName() << endl;

//  name = n;
//  age  = a;
//  lifespan = l;
}

Cow::~Cow()
{
  cout << "-- Chicken dtor: " << getName() << endl;
}

void Cow::print()
{
  Animal::print();
  cout << " and I'm a chicken that can produce " << eggCount << " eggs weekly" << endl;
}