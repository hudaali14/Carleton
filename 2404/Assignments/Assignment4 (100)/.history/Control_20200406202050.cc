#include <iostream>
using namespace std;
#include <string>

#include "Control.h"



void Control::launch()
{
    int    choice, id;
    string name, num, maj;
    float  gpa;

    // initStudents();
    // initDates();

    while (1) {
        view.showMenu(choice);

        if (choice == 0){
            students.print();
            dates.print();
            break;
        }
        if (choice == 1) {
            view.printStr("Number: ");
            view.readStr(num);
            view.printStr("Name: ");
            view.readStr(name);
            view.printStr("Major: ");
            view.readStr(maj);
            view.printStr("GPA: ");
            view.readFloat(gpa);

            Student* stu = new Student(num, name, maj, gpa);
            students += stu;
        }
        else if (choice == 2) {
            view.printStr("Id: ");
            view.readInt(id);

            try{
                students -= id;
            }catch(char* err){
                view.printStr(err);
            }

        }
        else if (choice == 3) {
            students.print();
        }
    }
}

void Control::initStudents(){
    Student* stu1 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu2 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu3 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu4 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu5 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu6 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu7 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu8 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu9 = new Student("101010101","Huda" , "CS", 1.0f);
    Student* stu10 = new Student("101010101","Huda" , "CS", 1.0f);

}

void Control::initDates(){

}

