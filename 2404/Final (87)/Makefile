final:	Array.h main.o Character.o Dragon.o DragonHallow.o Fighter.o Hero.o Position.o Quest.o random.o
	g++ -o final main.o Character.o Dragon.o DragonHallow.o Fighter.o Hero.o Position.o Quest.o random.o

main.o:	main.cc
	g++ -c main.cc

Character.o: Character.cc
	g++ -c Character.cc

Dragon.o: Dragon.cc
	g++ -c Dragon.cc

DragonHallow.o: DragonHallow.cc
	g++ -c DragonHallow.cc

Fighter.o: Fighter.cc
	g++ -c Fighter.cc

Hero.o: Hero.cc
	g++ -c Hero.cc

Position.o: Position.cc
	g++ -c Position.cc

Quest.o: Quest.cc
	g++ -c Quest.cc

random.o: random.cc
	g++ -c random.cc

clean:
	rm -f *.o final
