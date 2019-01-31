# Define some variables: 
SOURCES = reversi.c testReversi.c     # could also use patterns $(wildcard *.c)
HEADERS = reversi.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c11 -g -fPIC

# Next, we have the rules defining how the action corresponding to each target 
# should be performed. 
#
# Anatomy of a rule:
# Target : Dependencies
#    Bash commands (must be indented using TAB)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

tests: reversi.exe

reversi.exe: testReversi.o reversi.o
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	$(RM) $(OBJECTS) *.exe