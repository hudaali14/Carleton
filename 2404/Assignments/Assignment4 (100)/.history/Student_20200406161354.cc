#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Student.h"


Student::Student(string s1, string s2, string s3, float g) 
  : number(s1), name(s2), majorPgm(s3), gpa(g) { }

string Student::getName() const { return name; }
void Student::setName(string n) { name = n; }
string Student::getNumber() const { return number; }

bool Student::operator<(Student& s)
{
    return (getName() < s.getName());
}

bool Student::operator==(Student& s)
{
    return ( getName() < s.getName()
        && number == s.number);
}

ostream& operator<<(ostream& output, const Student& s)
{
  output<<"Student:  " << s.number << "  " << left << setw(10) << s.name << " "
                     << setw(15) << s.majorPgm << "   GPA: "
                     << fixed << setprecision(2) << setw(5) << right << s.gpa << endl;

  return output;
}