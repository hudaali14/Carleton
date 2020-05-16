#ifndef OBJECT_H
#define OBJECT_H

class Object
{
	public:
		Object();
		int GetId();
		
	private:
		int id;
		static int nextId;

};

#endif

