#include <iostream>
using namespace std;
#include <string>

#include "Control.h"



void Control::launch()
{
    int    choice, id;
    string name, num, maj;
    float  gpa;

    initStudents();
    initDates();

    while (1) {
        view.showMenu(choice);

        if (choice == 0){
            students.print();
            //dates.print();
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
            }catch(char const* err){
                view.printStr(err);
            }

        }
        else if (choice == 3) {
            students.print();
        }
    }
}

void Control::initStudents(){
    Student* stu1 = new Student("101010101", "Huda" , "CS", 1.0f);
    Student* stu2 = new Student("100000010", "Taehyung" , "Music", 10.0f);
    Student* stu3 = new Student("167284973", "Jungkook" , "Art", 11.5f);
    Student* stu4 = new Student("297482182", "Yoongi" , "Food Science", 10.5f);
    Student* stu5 = new Student("193846271", "Namjoon" , "Math", 12.0f);
    Student* stu6 = new Student("927489392", "Seokjin" , "Psychology", 10.0f);
    Student* stu7 = new Student("928346382", "Hoseok" , "Chemistry", 10.0f);
    Student* stu8 = new Student("293845657", "Luffy" , "English", 0.0f);
    Student* stu9 = new Student("394857382", "Buddy" , "Math", 1.0f);
    Student* stu10 = new Student("101010101", "Huda" , "CS", 1.0f);

    (students += stu1) += stu2;
    students += stu3;
    students += stu4;
    students += stu5;
    students += stu6;
    students += stu7;
    students += stu8;
    students += stu9;
    students += stu10;
}

void Control::initDates(){
    Date* date1 = new Date(1, 1, 2020);
    Date* date2 = new Date(3, 10, 1945);
    Date* date3 = new Date(17, 8, 1964);
    Date* date4 = new Date(3, 9, 1934);
    Date* date5 = new Date(24, 3, 2019);
    Date* date6 = new Date(5, 5, 1988);
    Date* date7 = new Date(1, 1, 2020);
    Date* date8 = new Date(1, 1, 2030);
    Date* date9 = new Date(2, 14, 1920);
    Date* date10 = new Date(12, 31, 1974);

    (dates += date1) += date2;
    dates += date3;
    dates += date4;
    dates += date5;
    dates += date6;
    dates += date7;
    dates += date8;
    dates += date9;
    dates += date10;

}

