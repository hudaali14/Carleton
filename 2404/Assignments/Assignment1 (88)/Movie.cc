#include <iostream>
using namespace std;
#include <string>
#include "Movie.h"

// Constructor
Movie::Movie(string t, int y){
    title = t;
    year = y;
}

//Copy constrcutor
Movie::Movie(const Movie& other){
    title = other.title;
    year = other.year;

}

// Destructor
Movie::~Movie(){
}

// Getter for year
int Movie::getYear(){
    return year;
}

// Prints title and year
void Movie::print(){
    cout << "** Year: " << year << "  Title: " << title << endl;
}
