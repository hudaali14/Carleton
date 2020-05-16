#ifndef CONTROL_H
#define CONTROL_H

#include "List.h"
#include "Student.h"
#include "Date.h"
#include "View.h"

/*

CONTROL CLASS
PURPOSE: Implements the control flow for the entire program
COMPLEX OR CRITICAL MEMBERS:
    - Library
    - View
    - Function launch():  Implements the program control flow
    - Function initBooks(): Initializes the books contained in the master collection

*/

class Control
{
    public:
        Control();
        void launch();

    private:
        List<Student> students;
        List<Date> dates;
        View view;
        void initStudents();
        void initDates();
};

#endif
