Huda Ali 101120387

Program & Purpose: Program executable is called a4. The purpose is to manage a group of students

Source/Header/Data Files:
	- Control.h
	- Control.cc
	- Date.h
	- Date.cc
	- List.h
	- Object.h
	- Object.cc
	- Student.h
	- Student.cc
	- View.h
	- View.cc
	- main.cc
	- Makefile

To compile: make you are first in the files directory then into the terminal type -> make
This will call the make file that will compile and link everything for you.
If you want to compile individual files then into the terminal type -> g++ -c filename.cc
In this case, filename represents your filename and this will compile the code.

To run: make sure you are first in the right directory then into the terminal type -> ./a4
In this case, filename represents your filename and this will run the code
To run with valgrind to check for any memory leaks into the terminal type -> valgrind --leak-check=yes ./a4
