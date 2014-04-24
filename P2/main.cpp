#include <iostream>
#include "integer.h"
#include "imath.h"

int primeTestLoop();
int addTestLoop();
int subTestLoop();
int mulTestLoop();
int  ioTestLoop();
int divTestLoop();

int main(int argc, char** argv)
{	//long long unsigned int i = 0ULL-4294967295ULL; 
	//std::cout << (i & LOW4) << " " << ((i & HIGH4) >> 32) << std::endl;
	return divTestLoop();
	return ioTestLoop();
	return mulTestLoop();
	return subTestLoop();
	return addTestLoop();
	return primeTestLoop();	
}

int primeTestLoop()
{
	integer i;
	integer j;
	do
	{	std::cout << "Please enter a number terminated by a carriage return (0 to quit): ";
		std::cin >> i;
		j = isPrime(i, integer(20));
		std::cout << std::endl << "the number: " << std::endl << i << std::endl;
		if(j == integer(1)) std::cout << "is prime." << std::endl;
		else std::cout << "is NOT prime.  The next prime number is: " <<std::endl << nextPrime(i, j) << std::endl;
	} while(i != 0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int addTestLoop()
{	integer i = 0, j = 0, k = 0;
	do
	{	std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		//k = 0;
		k = i + j;
		std::cout << "i + j: " << i << "+" << j << "=" << k << std::endl;
	} while(!(k == integer(0)));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int subTestLoop()
{       integer i = 0, j = 0, k = 0;
        do
        {       std::cout << "Please enter i: ";
                std::cin >> i;
                std::cout << "Please enter j: ";
                std::cin >> j;
                //k = 0;
                k = i - j;
                std::cout << "i - j: " << i << "-" << j << "=" << k << std::endl;
        } while(!(k == integer(0)));
        std::cout << std::endl;
        return EXIT_SUCCESS;
}

int mulTestLoop()
{       integer i = 0, j = 0, k = 0;
        do
        {       std::cout << "Please enter i: ";
                std::cin >> i;
                std::cout << "Please enter j: ";
                std::cin >> j;
                //k = 0;
                k = i * j;
                std::cout << "i * j: " << i << "*" << j << "=" << k << std::endl;
        } while(!(k == integer(0)));
        std::cout << std::endl;
        return EXIT_SUCCESS;
}

int ioTestLoop()
{	integer i = 0;
	do
	{	std::cout << "Enter any number (0 to quit): ";
		std::cin >> i;
		std::cout << "your number was: " << i << std::endl;
	} while(!(i == integer(0)));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int divTestLoop()
{       integer i = 0, j = 0, k = 0;
        do
        {       std::cout << "Please enter i: ";
                std::cin >> i;
                std::cout << "Please enter j: ";
                std::cin >> j;
                //k = 0;
                k = i / j;
                std::cout << "i / j: " << i << "/" << j << "=" << k << std::endl;
        } while(!(i == integer(0)));
        std::cout << std::endl;
        return EXIT_SUCCESS;
}
