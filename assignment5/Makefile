CXX = g++
CXXFLAGS = -g -std=c++14

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: testRot13cipher.exe testCaesar.exe testDate.exe

testRot13cipher.exe: testRot13cipher.o rot13cipher.o ioutils.o
	$(CXX) -o $@ $^

## Defie your own test* targets here and then add them to the all: target
## For example, if you implement a Caesar cipher, define a testCaesar.exe target
## and then add it to the dependencies of the all: target above. Do the 
## same for testDate.exe.

testCaesar.exe: testCaesar.o caesar.o ioutils.o
	$(CXX) -o $@ $^

testDate.exe: testDate.o date.o ioutils.o
	$(CXX) -o $@ $^

clean: 
	$(RM) *.o *.exe
