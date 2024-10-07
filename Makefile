CC = gcc
CFLAGS = -Wall 
LIBFLAGS = -lglfw -lGL

default: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c $(LIBFLAGS)