# Very simple makefile at the moment.
# Server Makefile for Celestia project.
CC=g++

CFLAGS= -c -Wall

all: celest

celest: main.o celest.o
	$(CC) main.o celest.o -o celest

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

celest.o: celest.cpp
	$(CC) $(CFLAGS) celest.cpp

clean:
	rm -rf *.o celest