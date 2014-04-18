CXX=g++
CC=gcc
LD=g++
CXXFLAGS=$(CFLAGS) -std=c++11
CFLAGS=-c -Wall -Werror -O3
LDFLAGS=
CXXSOURCES=main.cpp integer.cpp integer_iostream.cpp integer_mul.cpp isPrime.cpp jacobi.cpp
CSOURCES=
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.c=.o)
OBJECTS=$(COBJECTS) $(CXXOBJECTS)
EXECUTABLE=isPrime
.PHONY=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o $(EXECUTABLE)

test: $(EXECUTABLE)
	./doalg
