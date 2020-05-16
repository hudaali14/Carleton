#ifndef MOVIE_H
#define MOVIE_H


class Movie
{
  public:
    Movie(string="", int=0);
    ~Movie();
    Movie(const Movie&);
    void addMovie();
    void print();

  private:
    string title;
    int    year;
};

#endif
