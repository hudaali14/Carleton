#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "List.h"
#include "Logger.h"

class Library
{
    public:


    private:
        List master;
        vector<Logger*> barnyard;
};

#endif
