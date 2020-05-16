#ifndef OBJECT_H
#define OBJECT_H

/*

OBJECT CLASS
PURPOSE: Object class with unique identifier

*/

class Object
{
	public:
		Object();
		~Object();
		int getID();
		
	private:
		int id;
		static int nextId;

};

#endif

