#ifndef MOVIE_H
#define MOVIE_H


class Movie
{
    public:
        Movie(string="", int=0);
        Movie(const Movie&);
        int getYear();
        void set(string t, int y);
        ~Movie();
        void print();

    private:
        string title;
        int    year;
};

#endif
