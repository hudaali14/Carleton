#include "Object.h"

int Object::nextId = 1001;

Object::Object()
{
	id = nextId;
	++nextId;
}
