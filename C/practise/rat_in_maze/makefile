# Makefile for the compilaation of this project.
#
#  Name: Ramji Misra
#

CC = gcc
CFLAGS = -c -g -Wall
IFLAGS = -I$(INC)
INC = ./h/
OBJ = ./obj/
SRC = ./src/
BIN = ./bin/

all: $(BIN)rat_in_maze

$(BIN)rat_in_maze: $(OBJ)rat_in_maze.o $(OBJ)utility.o
	$(CC) -o $(BIN)rat_in_maze $(OBJ)rat_in_maze.o $(OBJ)utility.o

$(OBJ)rat_in_maze.o: $(SRC)rat_in_maze.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)rat_in_maze.c
	mv rat_in_maze.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)utility.c
	mv utility.o $(OBJ)

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(BIN)rat_in_maze

