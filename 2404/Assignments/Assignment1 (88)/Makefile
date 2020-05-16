Movies: Movie.o MovieGroup.o main.o
	g++ -o Movies MovieGroup.o Movie.o main.o

Movie.o: Movie.cc Movie.h
	g++ -c Movie.cc

MovieGroup.o: MovieGroup.cc MovieGroup.h
	g++ -c MovieGroup.cc

main.o: main.cc MovieGroup.h Movie.h
	g++ -c main.cc

clean:
	rm -f *.o Movies
