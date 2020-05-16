#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g) 
  : number(s1), name(s2), majorPgm(s3), gpa(g){
    cout << "Default Student ctor -- " << name << endl;
   }

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }

bool Student::operator<(Student& s)
{
    return (getName() < s.getName());
}

bool Student::operator==(Student& s)
{
    return ( getName() < s.getName()
        && number == s.number);
}

ostream& operator<<(ostream& output, Student& s)
{
  output<<"ID:" << s.getID() << left << setw(5) << "  " <<"Student ID: "<< s.number << "  "  << setw(20) << s.name << " "
                     << setw(10) << s.majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << s.gpa << endl;

  return output;
}