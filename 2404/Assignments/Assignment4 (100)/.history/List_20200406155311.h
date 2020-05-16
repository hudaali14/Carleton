#ifndef LIST_H
#define LIST_H

#include "Student.h"

class List
{
    class Node 
    {
        public:
            Student* data;
            Node*    next;
    };

    public:
        List();
        ~List();
        void add(Student*);
        void del(const string, Student**);
        void print() const;

    private:
        Node* head;
};

#endif
