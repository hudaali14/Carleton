#ifndef MOVIEGROUP_H
#define MOVIEGROUP_H

#include "Movie.h"

#define MAX_MOVIEGROUP 64;

class MovieGroup
{
    public:
        MovieGroup(int=0);
        ~MovieGroup();
        MovieGroup(const MovieGroup&);
        void print();

    private:
        int size;
        Movie *collection[];
};

#endif
