
INC = ../h/
SRC = ../src/
OBJ = ../obj/
BIN = ../bin/
CC = gcc
CFLAGS = -c -g -Wall -Werror
IFLAGS = -I$(INC)

all: $(BIN)server $(BIN)client
$(BIN)server: $(OBJ)server.o $(OBJ)utility_func.o 
	$(CC) -o $(BIN)server $(OBJ)server.o $(OBJ)utility_func.o
	
$(BIN)client: $(OBJ)client.o $(OBJ)utility_func.o
	$(CC) -o $(BIN)client $(OBJ)client.o $(OBJ)utility_func.o

$(OBJ)server.o: $(SRC)server.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)server.c
	mv server.o $(OBJ);

$(OBJ)client.o: $(SRC)client.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)client.c
	mv client.o $(OBJ);

$(OBJ)utility_func.o: $(SRC)utility_func.c
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)utility_func.c
	mv utility_func.o $(OBJ)

clean:
	rm -rf $(OBJ)*.o;
	rm -rf $(BIN)server;
	rm -rf $(BIN)client;
