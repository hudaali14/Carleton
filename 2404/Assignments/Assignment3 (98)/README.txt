Huda Ali 101120387

Program & Purpose: Program executable is called a3. The purpose is to implement a simplified version of the Observer design pattern. Implemented two concrete "event logger" classes that observe changes to a library, specifically the events of checking in and checking out of books

Source/Header/Data Files:
	- Book.h
	- Book.cc
	- Control.h
	- Control.cc
	- Library.h
	- Library.cc
	- List.h
	- List.cc
	- Logger.h
	- Logger.cc
	- View.h
	- View.cc
	- main.cc
	- Makefile

To compile: make you are first in the files directory then into the terminal type -> make
This will call the make file that will compile and link everything for you.
If you want to compile individual files then into the terminal type -> g++ -c filename.cc
In this case, filename represents your filename and this will compile the code.

To run: make sure you are first in the right directory then into the terminal type -> ./a3
In this case, filename represents your filename and this will run the code
To run with valgrind to check for any memory leaks into the terminal type -> valgrind --leak-check=yes ./a3
