#include <iostream>
using namespace std;
#include <string>
#include "MovieGroup.h"


MovieGroup::MovieGroup(int s)
{
    size = s;
}

MovieGroup::MovieGroup(const MovieGroup& other)
{
  
}

void addMovie(Movie* m){
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
    delete [] this->collection;
    cout<<"-- Movie dtor:  "<< title <<endl;
}

void Movie::print()
{
    cout<<"** Movie "<< title <<" Year "<< year <<endl;
}
