#ifndef DATE_H
#define DATE_H

#include "Object.h"

/*

DATE CLASS
PURPOSE: Date class with day, month and year
COMPLEX OR CRITICAL MEMBERS:
    - Function operator<<(ostream&, Student&): Overloaded stream insertion operator
    and prints date 
    - Function operator<(Date&): Returns true if left-hand side date is 
    considered the lesser if its date chronologically
    - Function operator==(Date&): Returns true if their names and
    their student numbers are equal
    
*/

class Date : public Object
{
    friend ostream& operator<<(ostream&, Date&);

    public:
        Date(int=0, int=0, int=2000);
        ~Date();
        void setDate(int, int, int);
        void printLong() const;
        void printLong();
        bool operator<(Date&);
        bool operator==(Date&);

    private:
        int day;
        int month;
        int year;
        int  lastDayInMonth();
        bool leapYear();
        string getMonthStr() const;
};

#endif
