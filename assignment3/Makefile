# Define some variables: 
SOURCES = reversi.c  testReversi.c   # could also use patterns $(wildcard *.c)
HEADERS = reversi.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c11 -g -fPIC

.PHONY: reversi
reversi: reversi.exe

%.o: %.c
	$(CC) -c $(CFLAGS) $<

tests: reversi.exe

reversi.exe: testReversi.o reversi.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJECTS) *.exe