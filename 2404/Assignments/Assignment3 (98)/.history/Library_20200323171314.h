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

    private:
        List master;
        vector<Logger*> loggers;
};

#endif
