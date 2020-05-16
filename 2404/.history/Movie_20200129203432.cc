#include <iostream>
using namespace std;
#include <string>
#include "Movie.h"

Movie::Movie(string t, int y)
{
    title        = t;
    year         = y;
    cout<<"-- default Movie ctor:  "<< title <<endl;
}

Movie::Movie(const Movie& other)
{
    title     = other.title;
    year      = other.year;

    cout<<"-- copy ctor:  "<< title <<endl;
}


int Movie::getYear(){
    return year;
}

void Movie::set(string t, int y){
    title = t;
    year  = y;
}

void addMovie(Movie* arr, int& size, string title, int year){
    int insertionPoint;
    sizeOfArray = sizeof(arr)/sizeof(Movie);
    if(sizeOfArray != *size){
        for(int i=0; i<size; i++){
            if(arr[i]->year==0){
                insertionPoint=i;
            }
        }
        for(int i=size; i>0; i--){
            arr[i+1]=arr[i];
        }
        set(title,year);
        size++;
    }
}

Movie::~Movie()
{
    cout<<"-- Movie dtor:  "<< title <<endl;
}

void Movie::print()
{
    cout<<"** Movie "<< title <<" Year "<< year <<endl;
}
