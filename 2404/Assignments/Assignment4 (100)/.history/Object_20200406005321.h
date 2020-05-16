#ifndef OBJECT_H
#define OBJECT_H

class Object
{
	public:
		Object();
		int getId();
		
	private:
		int id;
		static int nextId;

};

#endif

