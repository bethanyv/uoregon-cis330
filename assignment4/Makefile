# Define some variables: 
SOURCES = reversi.cpp  testReversi.cpp
HEADERS = reversi.h
OBJECTS = $(SOURCES:.cpp=.o)
LIBS = -lm

CC = g++
CFLAGS = -std=c++14 -g

.PHONY: reversi
reversi: reversi.exe

%.o: %.cpp
	$(CC) -c $(CFLAGS) $<

tests: reversi.exe

reversi.exe: testReversi.o reversi.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJECTS) *.exe