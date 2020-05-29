#include <iostream>
using namespace std;
#include <string>

#include "Cow.h"

Cow::Cow(string n, int a, int l, string m) : milkTime(m), Animal(n,a,l)
{
}

Cow::~Cow()
{
}

void Cow::print() const
{
  Animal::print();
  cout << "     and I'm a cow that gets milked at " << milkTime << endl;
}
