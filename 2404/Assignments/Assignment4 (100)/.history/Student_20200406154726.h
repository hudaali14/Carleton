#ifndef STUDENT_H
#define STUDENT_H

#include "Object.h"

class Student : public Object
{
    friend ostream& operator<<(ostream&, const Student&);

    public:
        Student(string="000000000", string="Hey you!", string="basket-weaving", float=0.0f);
        string getName() const;
        void setName(string n);
        bool operator<(Student&);

    private:
        const string number;
        string name;
        string majorPgm;
        float  gpa;
};

#endif
