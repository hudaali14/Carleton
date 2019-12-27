OBJ = mazes.o mazeDisplay.o

all: maze display
	gcc -o mazes $(OBJ) -g -Wall -lX11

maze: mazes.c graphSet.h mazeDisplay.h
	gcc -c mazes.c -g

display: mazeDisplay.c mazeDisplay.h graphSet.h
	gcc -c makeDisplay.c -g

# clean:
# 	rm -f(OBJ) mazes