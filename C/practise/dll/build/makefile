
BIN = ../bin/
OBJ = ../obj/
INC = ../h/
SRC = ../src/
CC = gcc
CFLAGS = -c -g -Wall -Werror
IFLAGS = -I$(INC)

all: $(BIN)dll

$(BIN)dll: $(OBJ)dll.o $(OBJ)utility.o
	$(CC) -o $(BIN)dll $(OBJ)dll.o $(OBJ)utility.o

$(OBJ)dll.o: $(SRC)dll.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)dll.c
	mv dll.o $(OBJ)

$(OBJ)utility.o: $(SRC)utility.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)utility.c
	mv utility.o $(OBJ)

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(BIN)dll
