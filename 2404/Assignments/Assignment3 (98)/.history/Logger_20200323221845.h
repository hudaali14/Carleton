#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"

/*

LOGGER CLASS
PURPOSE: Tracks the checking in and checking out of books in
the library. These classes also serve as the observers in our Observer design pattern
COMPLEX OR CRITICAL MEMBERS:
    - Linked list of books
    - Function update(): Virtual function that updates list of books based on information 
    provided in book parameter

*/

class Logger
{
    public:
        Logger(string = "");
        ~Logger();
        virtual void update(Book*);
        void printLogs();

    protected:
        string name;
        List books;

};

/*

CHECKINLOGGER CLASS
PURPOSE: Tracks which books have been checked into the library
the library. These classes also serve as the concrete observers in our Observer design pattern
COMPLEX OR CRITICAL MEMBERS:
    - Function update(): Virtual function that updates list of books based on information 
    provided in book parameter

*/

class CheckInLogger : public Logger
{
    public:
        CheckInLogger();
        ~CheckInLogger();
        virtual void update(Book*);

};

/*

CHECKOUTLOGGER CLASS
PURPOSE: Tracks which books have been checked out of the library
the library. These classes also serve as the concrete observers in our Observer design pattern
COMPLEX OR CRITICAL MEMBERS:
    - Function update(): Virtual function that updates list of books based on information 
    provided in book parameter

*/

class CheckOutLogger : public Logger
{
    public:
        CheckOutLogger();
        ~CheckOutLogger();
        virtual void update(Book*);

};

#endif
