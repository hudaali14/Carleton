#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"

class Library
{
    public:
        Library();
        ~Library();
        void subscribe(Logger* logger);
        void notify(Book* b);
        void add(Book* b);
        void Book* find(int id);
        void checkOut(Book* b);
        void checkIn(Book* b);
        void print();

    private:
        List master;
        vector<Logger*> loggers;
};

#endif
