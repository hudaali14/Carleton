#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
using namespace std;
#include "Book.h"
#include "List.h"

class Logger
{
    public:
        Logger(string);
        ~Logger();

    protected:
        string name;


};

class CheckInLogger 
{
    public:

};

class CheckOutLogger 
{
    public:

};

#endif
