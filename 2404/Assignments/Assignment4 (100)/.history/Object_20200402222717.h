#pragma once
class Object
{
public:
	Object();
	int GetId() { return id; }
private:
	int id;
	static int nextId;
};

