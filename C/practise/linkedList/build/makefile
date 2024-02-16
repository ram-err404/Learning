# Makefile
#
# Name: Ramji Misra

INC = ../h/
OBJ = ../obj/
BIN = ../bin/
SRC = ../src/
CC = gcc
CFLAGS = -c -g -Wall 
IFLAGS = -I$(INC)

all: $(BIN)linkedList

$(BIN)linkedList: $(OBJ)linkedList.o $(OBJ)utility.o
	$(CC) -o $(BIN)linkedList $(OBJ)linkedList.o $(OBJ)utility.o

$(OBJ)linkedList.o: $(SRC)linkedList.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)linkedList.c
	mv linkedList.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)utility.c
	mv utility.o $(OBJ)

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(BIN)linkedList
	echo "Cleaning successful"
