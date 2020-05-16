#ifndef LIST_H
#define LIST_H

#include "Book.h"

/*

LIST CLASS
PURPOSE: Singly linked list that uses Book pointers as data
COMPLEX OR CRITICAL MEMBERS:
  - Node class: Stores data and next pointers
  - Function del(const int, Book**): Deletes book to match specified id
  - Function add(Book*):  Adds book in ascending order by author name
  - Function find(int id): Returns book with matching id in list. If not found returns NULL

NODE CLASS
PURPOSE: Stores data and next pointers

*/

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
