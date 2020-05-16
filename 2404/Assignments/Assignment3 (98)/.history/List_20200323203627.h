#ifndef LIST_H
#define LIST_H

#include "Book.h"

class List
{
    class Node 
    {
        public:
            Book* data;
            Node* next;
    };

    public:
        List();
        ~List();
        void add(Book*);
        void del(const int, Book**);
        Book* find(int);
        void cleanup();
        void print() const;

    private:
        Node* head;
};

#endif
