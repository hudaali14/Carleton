#ifndef STUDENT_H
#define STUDENT_H

#include "Object.h"

/*

STUDENT CLASS
PURPOSE: Student class with a student number, name, and checkedIn value
COMPLEX OR CRITICAL MEMBERS:
    - Function operator<(Date&): Returns true if left-hand side student is 
    considered the lesser if its name comes first in alphabetical order
    - Function operator==(Date&): Returns true if their names and
    their student numbers are equal
    
*/

class Student : public Object
{
    friend ostream& operator<<(ostream&, Student&);

    public:
        Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f);
        string getName() const;
        string getNumber() const;
        void setName(string n);
        bool operator<(Student&);
        bool operator==(Student&);

    private:
        const string number;
        string name;
        string majorPgm;
        float  gpa;
};

#endif
