#include <iostream>
using namespace std;

#include "Movie.h"
#include "MovieGroup.h"

void initMovies(MovieGroup&, MovieGroup&);

int main(){

    //Declare Calvin and Hobbes
    MovieGroup Calvin;
    MovieGroup Hobbes;
    // Initializes movie groups Calvin and Hobbes
    initMovies(Calvin, Hobbes);
    // Declare and intitalize allMovies with the content of Calvin
    MovieGroup allMovies = Calvin;
    // Merges allMovies with Hobbes
    allMovies.merge(Hobbes);

    cout << "Calvin:" << endl;
    Calvin.print();
    cout << "Hobbes:" << endl;
    Hobbes.print();
    cout << "All Movies:" << endl;
    allMovies.print();


    return 0;
}

void initMovies(MovieGroup& movies1, MovieGroup& movies2){
    movies1.add(new Movie("E.T. The Extra-Terrestrial", 1982));
    movies1.add(new Movie("Metropolis", 1927));
    movies1.add(new Movie("Gravity", 2013));
    movies1.add(new Movie("Arrival", 2016));
    movies1.add(new Movie("Star Wars: The Last Jedi", 2017));
    movies1.add(new Movie("Alien", 1979));
    movies1.add(new Movie("War for the Planet of the Apes", 2017));
    movies1.add(new Movie("Wall-E", 2008));
    movies1.add(new Movie("Star Trek", 2009));
    movies1.add(new Movie("Terminator", 1984));
    movies1.add(new Movie("Invasion of the Body Snatchers", 1956));
    movies1.add(new Movie("The Day the Earth Stood Still", 1951));
    movies1.add(new Movie("Jurassic Park", 1993));
    movies1.add(new Movie("Back to the Future", 1985));
    movies1.add(new Movie("Blade Runner", 1982));

    movies2.add(new Movie("The Wizard of Oz", 1939));
    movies2.add(new Movie("Citizen Kane", 1941));
    movies2.add(new Movie("Casablanca", 1942));
    movies2.add(new Movie("Psycho", 1960));
    movies2.add(new Movie("King Kong", 1933));
    movies2.add(new Movie("Rear Window", 1954));
    movies2.add(new Movie("Rebecca", 1940));
    movies2.add(new Movie("Vertigo", 1958));
    movies2.add(new Movie("Lawrence of Arabia", 1962));
    movies2.add(new Movie("The Grapes of Wrath", 1940));
    movies2.add(new Movie("Chinatown", 1974));
    movies2.add(new Movie("Gone with the Wind", 1939));
    movies2.add(new Movie("Invasion of the Body Snatchers", 1956));
    movies2.add(new Movie("It's a Wonderful Life", 1946));
    movies2.add(new Movie("Doctor Zhivago", 1965));
}
