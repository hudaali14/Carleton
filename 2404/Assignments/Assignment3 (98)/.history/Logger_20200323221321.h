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
        Logger(string = "");
        ~Logger();
        virtual void update(Book*);
        void printLogs();

    protected:
        string name;
        List books;

};

class CheckInLogger : public Logger
{
    public:
        CheckInLogger();
        ~CheckInLogger();
        virtual void update(Book*);

};

class CheckOutLogger : public Logger
{
    public:
        CheckOutLogger();
        ~CheckOutLogger();
        virtual void update(Book*);

};

#endif
