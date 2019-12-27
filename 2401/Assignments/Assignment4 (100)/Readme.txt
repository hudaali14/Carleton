Huda Ali 101120387

Source Files:
	- mazes.c
	- mazeDisplay.c
	- mazeDisplay.h
	- graphSet.h
	- Makefile

To compile: make you are first in the files directory then into the terminal type -> make 
This will call the make file that will compile everything for you. If you want to compile individual files then into the terminal type -> gcc -o filename filename.c 
In this case, filename represents your filename and this will link and compile the code.

To run: make you are first in the files directory then into the terminal type -> ./mazes
If you want to run individual files then into the terminal type -> ./filename 
In this case, filename represents your filename and this will run the code
To run with valgrind to check for any leaks into the terminal type -> valgrind --leak-check=yes ./mazes

