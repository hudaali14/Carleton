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
    - List<Student> students
    - List<Date> dates
    - View
    - Function launch():  Implements the program control flow
    - Function initStudents(): Initializes the students
    - Function initDates(): Initializes the dates

*/

class Control
{
    public:
        void launch();
        void initStudents();
        void initDates();

    private:
        List<Student> students;
        List<Date> dates;
        View view;
};

#endif
