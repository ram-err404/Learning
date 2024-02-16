#This is the Makefile for compiling Thread.c

$(CC) =gcc
$(CFLAGS) =-c -Wall
$(bin) =../bin/
$(obj) =../obj/

all : $(obj)Thread.o
	$(CC) -o $(bin)Thread $(CFLAGS) $(obj)Thread.o 

$(obj)Thread.o :
	$(CC) $(CFLAGS) Thread.c -lpthread

clean: 
	rm -rf $(obj)*
