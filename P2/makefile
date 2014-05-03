CXX=g++
CC=gcc
LD=g++
CXXFLAGS=$(CFLAGS) -std=c++11
CFLAGS=-c -Wall -Werror -Wextra -DNDEBUG -O3
LDFLAGS=
CXXSOURCES=main.cpp integer.cpp integer_add.cpp integer_sub.cpp integer_mul.cpp integer_div.cpp integer_iostream.cpp jacobi.cpp isPrime.cpp nextPrime.cpp b_pow_N_minus_1_mod_N.cpp integer_random.cpp
CSOURCES= dshrandom.c
HEADERS=integer.h imath.h
CXXOBJECTS=$(CXXSOURCES:.cpp=.o)
COBJECTS=$(CSOURCES:.c=.o)
OBJECTS=$(COBJECTS) $(CXXOBJECTS)
EXECUTABLE=isPrime
.PHONY=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS) makefile
	$(CXX) $(CXXFLAGS) $< -o $@

.c.o: $(HEADERS) makefile
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o $(EXECUTABLE)

test: $(EXECUTABLE)
	./doalg
