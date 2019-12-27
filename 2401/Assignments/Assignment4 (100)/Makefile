all: maze display
	gcc -o mazes mazes.o mazeDisplay.o -g -lX11

maze: mazes.c mazeDisplay.h graphSet.h
	gcc -c mazes.c -g

display: mazeDisplay.c mazeDisplay.h graphSet.h
	gcc -c mazeDisplay.c -g

clean:
	rm -f mazes.o mazeDisplay.o mazes
