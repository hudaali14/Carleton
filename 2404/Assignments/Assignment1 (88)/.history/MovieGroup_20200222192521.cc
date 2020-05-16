#include <iostream>
using namespace std;
#include <string>
#include "MovieGroup.h"


//Constructor
MovieGroup::MovieGroup(int s){
    size = s;
}

//Copy constructor
MovieGroup::MovieGroup(const MovieGroup& other){
    for (int i = 0; i < other.size; i++){
        size = other.size;
        movies[i] = new Movie(*(other.movies[i]));
    }
}

// Destructor
MovieGroup::~MovieGroup() {
    for (int i = 0; i < size; i++){
        delete movies[i];
    }
}

// Print all movies in movies array
void MovieGroup::print() {
    for (int i = 0; i < size; i++){
        movies[i]->print();
    }
}

// Add movie pointer to movies array
void MovieGroup::add(Movie* m){
    //If the array is already full return
    if(size == MAX_MOVIEGROUP){
      return;
    }
    //Declare index
    int index;
    //If there is nothing in the array then we're adding to the first index
    if(size == 0){
        index = 0;
    }else{
        for(int i = 0; i < size; i++){
            // Loop through till we find an item less than m then set index
            if (m->getYear() <= movies[i]->getYear()){
                index = i;
                break;
            // Means item might be at end of array
            }else{
                index = size;
            }
        }
        // If the movie we're adding is not at the end of the array, then shift ther elements
        if(index != size){
            for (int i = size; i >= index; i--){
                movies[i + 1] = movies[i];
            }
        }
    }
    //Set movies at index to m and increase size
    movies[index] = m;
    size++;
}

// Adds all movies from mg to movies array (even duplicates)
void MovieGroup::merge(MovieGroup& mg){
    for(int i = 0; i < mg.size; i++){
        // If we reach the max size for the array we're adding to then return
        if(size == MAX_MOVIEGROUP){
            return;
        }
        // Allocates for new Movie then adds to array
        Movie *addMovie = new Movie(*(mg.movies[i]));
        add(addMovie);
    }
}
