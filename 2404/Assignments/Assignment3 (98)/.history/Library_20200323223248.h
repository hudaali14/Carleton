#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"

/*

LIBRARY CLASS
PURPOSE: Manages a collection of books
COMPLEX OR CRITICAL MEMBERS:
    - Function subscribe(Logger* logger): Adds the given logger object to the
    collection of observers
    - Function notify(Book* b): Loops over every logger object in the collection of
    observers, and calls its update() function with the given book parameter b
    - Function add(Book* b): Adds the given book b to the collection of books, and
    notifies all logger objects of the change
    - Function find(int id): Searches the book collection for a book with the given 
    identifier id, and returns either that book pointer or null if the book was not found
    - Function checkOut(Book* b): Checks book b out of the library and notifies all
    the logger objects of the change
    - Function checkIn(Book* b): Checks book b into the library and notifies all the
    logger objects of the change
    
*/


class Library
{
    public:
        Library();
        ~Library();
        void subscribe(Logger*);
        void notify(Book*);
        void add(Book*);
        Book* find(int);
        void checkOut(Book*);
        void checkIn(Book*);
        void print();

    private:
        List master;
        vector<Logger*> loggers;
};

#endif
