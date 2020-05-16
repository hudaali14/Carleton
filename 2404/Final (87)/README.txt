Program Author: Huda Ali 101120387

Program & Purpose: Program executable is called final. The purpose is to create a simulation for Timmy or Harold
to make their way across Dragon’s Hollow (moving from the left-hand side to the right-hand side), and rescue the
Emerald, all without dying.

Source/Header/Data Files:
	- Array.h
	- Character.h
	- Character.cc
	- Dragon.h
	- Dragon.cc
	- DragonHallow.h
	- DragonHallow.cc
	- Fighter.h
	- Fighter.cc
	- Hero.h
	- Hero.cc
	- Position.h
	- Position.cc
	- Quest.h
	- Quest.cc
	- random.c
	- main.cc
	- Makefile

Innovative feature: I wanted to give the dragon more functionality. Every update the dragon launches an attack
along its row. The row is set to where the dragon is but the column is chosen randomly. If a hero lands on this
attack it loses 10 health points. If a fighter lands on this attack it gains 5 points.

To compile: make you are first in the files directory then into the terminal type -> make
This will call the make file that will compile and link everything for you.
If you want to compile individual files then into the terminal type -> g++ -c filename.cc
In this case, filename represents your filename and this will compile the code.

To run: make sure you are first in the right directory then into the terminal type -> ./final
In this case, filename represents your filename. This will run the code
To run with valgrind to check for any memory leaks into the terminal type -> valgrind --leak-check=yes ./final
