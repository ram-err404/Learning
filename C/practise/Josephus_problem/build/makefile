# Makefile
#
# Name: Ramji Misra
#

OBJ = ../obj/
INC = ../h/
BIN = ../bin/
SRC = ../src/
CC = gcc
CFLAGS = -c -g -Wall -Werror
IFLAGS = -I$(INC)

all: $(BIN)josephus

$(BIN)josephus: $(OBJ)josephus.o $(OBJ)utility.o
	$(CC) -o $(BIN)josephus $(OBJ)josephus.o $(OBJ)utility.o

$(OBJ)josephus.o: $(SRC)josephus.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)josephus.c
	mv josephus.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)utility.c
	mv utility.o $(OBJ)

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(BIN)josephus
