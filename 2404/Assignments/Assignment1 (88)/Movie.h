#ifndef MOVIE_H
#define MOVIE_H


class Movie
{

// Public methods
public:
    // Constructor
    Movie(string = "", int = 0);
    // Copy Constructor
    Movie(const Movie&);
    // Destrcutor
    ~Movie();
    // Getter for year
    int getYear();
    //Print title and Year
    void print();

// Private data members
private:
    string title;
    int year;
};

#endif
