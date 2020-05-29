a2:	main.o Animal.o AgCoop.o Chicken.o Control.o Cow.o Farm.o List.o Pig.o View.o
	g++ -o a2 main.o Animal.o AgCoop.o Chicken.o Control.o Cow.o Farm.o List.o Pig.o View.o

main.o:	main.cc Control.h
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h
	g++ -c Animal.cc

AgCoop.o:	AgCoop.cc AgCoop.h Farm.h Animal.h
	g++ -c AgCoop.cc

Chicken.o:	Chicken.cc Chicken.h Animal.h
	g++ -c Chicken.cc

Control.o:	Control.cc Control.h AgCoop.h View.h
	g++ -c Control.cc

Cow.o:	Cow.cc Cow.h Animal.h
	g++ -c Cow.cc

Farm.o:	Farm.cc Farm.h List.h
	g++ -c Farm.cc

List.o:	List.cc List.h Animal.h
	g++ -c List.cc

Pig.o:	Pig.cc Pig.h Animal.h
	g++ -c Pig.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o a2
