all: compile run

compile: main.c maze.c maze.h
	gcc -o maze.o main.c maze.c -lcurses

run:
	./maze.o maze.txt
