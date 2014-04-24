CXX=g++
CC=gcc
LD=g++
CXXFLAGS=$(CFLAGS) -std=c++11
CFLAGS=-c -Wall -Werror -O3 -g
LDFLAGS=
CXXSOURCES=main.cpp integer.cpp integer_add.cpp integer_sub.cpp integer_mul.cpp integer_div.cpp integer_iostream.cpp jacobi.cpp isPrime.cpp nextPrime.cpp
CSOURCES=
HEADERS=integer.h imath.h
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.c=.o)
OBJECTS=$(COBJECTS) $(CXXOBJECTS)
EXECUTABLE=isPrime
.PHONY=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@

.c.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o $(EXECUTABLE)

test: $(EXECUTABLE)
	./doalg
