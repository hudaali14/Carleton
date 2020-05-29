#include <iostream>
using namespace std;
#include <string>

#include "Pig.h"

Pig::Pig(string n, int a, int l, int p) : penNumber(p), Animal(n,a,l)
{
}

Pig::~Pig()
{
}

void Pig::print() const
{
  Animal::print();
  cout << "     and I'm a pig and I live in pen number " << penNumber << endl;
}
