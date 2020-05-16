#include <iostream>
using namespace std;

#include "Object.h"

int Object::nextId = 1001;

Object::Object()
{
	id = nextId;
	++nextId;
}

Object::~Object()
{
}

int Object::getID(){ return id; }