#include <iostream>
using namespace std;
#include <string>

#include "Control.h"
#include "View.h"
#include "Student.h"


void Control::launch()
{
    int    choice, id;
    string name, num, maj;
    float  gpa;


    while (1) {
        view.showMenu(choice);

        if (choice == 0)
            break;

        if (choice == 1) {
            view.printStr("Number: ");
            view.readStr(num);
            view.printStr("Name: ");
            view.readStr(name);
            view.printStr("Major: ");
            view.readStr(maj);
            view.printStr("GPA: ");
            view.readFloat(gpa);


        }
        else if (choice == 2) {
            view.printStr("Id: ");
            view.readInt(id);


        }
        else if (choice == 3) {

        }
    }


}


