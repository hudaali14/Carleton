#ifndef MOVIEGROUP_H
#define MOVIEGROUP_H

#include "Movie.h"

#define MAX_MOVIEGROUP 64

class MovieGroup {

// Public methods
public:

    // Constructor
    MovieGroup(int = 0);
    // Copy constructor
    MovieGroup(const MovieGroup&);
    // Destructor
    ~MovieGroup();
    // Print all movies in movies array
    void print();
    // Adds movie to movies array
    void add(Movie*);
    // Merges all movies into movies array
    void merge(MovieGroup&);

// Private data members
private:
    Movie* movies[MAX_MOVIEGROUP];
    int size;
};

#endif
