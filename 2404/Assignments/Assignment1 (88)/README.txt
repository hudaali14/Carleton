Huda Ali 101120387

Program & Purpose: Program executable is called Movies. The purpose is to manage movie collections/groups.

Source/Header/Data Files:
	- Movies.h
	- Movies.cc
	- MovieGroup.h
	- MovieGroup.cc
	- main.cc
	- Makefile

To compile: make you are first in the files directory then into the terminal type -> make
This will call the make file that will compile and link everything for you.
If you want to compile individual files then into the terminal type -> g++ -c filename.cc
In this case, filename represents your filename and this will compile the code.

To run: make sure you are first in the right directory then into the terminal type -> ./Movies
In this case, filename represents your filename and this will run the code
To run with valgrind to check for any memory leaks into the terminal type -> valgrind --leak-check=yes ./Movies
