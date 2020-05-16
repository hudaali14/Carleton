a2:	main.o Animal.o AgCoop.o Chicken.o Control.o Cow.o Farm.o List.o Pig.o View.o
	g++ -o a2 main.o Animal.o AgCoop.o Chicken.o Control.o Cow.o Farm.o List.o Pig.o View.o

main.o:	main.cc
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h
	g++ -c Animal.cc

AgCoop.o:	AgCoop.cc AgCoop.h
	g++ -c AgCoop.cc

Chicken.o:	Chicken.cc Chicken.h
	g++ -c Chicken.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

Cow.o:	Cow.cc Cow.h
	g++ -c Cow.cc

Farm.o:	Farm.cc Farm.h
	g++ -c Farm.cc

List.o:	List.cc List.h Animal.h
	g++ -c List.cc

Pig.o:	Pig.cc Pig.h
	g++ -c Pig.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o a2
