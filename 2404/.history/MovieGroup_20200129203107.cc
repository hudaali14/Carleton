#include <iostream>
using namespace std;
#include <string>
#include "Movie.h"

Movie::Movie(int s)
{
    size = s;
    cout<<"-- default Movie ctor:  "<< title <<endl;
}

MovieGroup::MovieGroup(const MovieGroup& other)
{
  

    cout<<"-- copy ctor:  "<< title <<endl;
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
