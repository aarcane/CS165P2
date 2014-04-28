#include <iostream>
#include "integer.h"
#include "imath.h"
#include <map>
#include <cassert>
#include <climits>

int primeTestLoop();
int addTestLoop();
int subTestLoop();
int mulTestLoop();
int  ioTestLoop();
int divTestLoop();
int equTestLoop();
int cmpTestLoop();

void usage();


int main(int argc, char** argv)
{	int (*d)();
	std::map<std::string, int (*)()> driver;
	std::string cmd;
	
	std::cout << std::abs(-100LL) << std::endl;
	//populate the driver function map
	driver.insert(std::pair<std::string, int(*)()>("div",	divTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("d",	divTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("mul",	mulTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("m",	mulTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("add",	addTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("a",	addTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("sub",	subTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("s",	subTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("io",	ioTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("i",	ioTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("prime",	primeTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("p",	primeTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("equal", equTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("e",	equTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("cmp",	cmpTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("c",	cmpTestLoop));

	//did we pass an argument?
	if(argc == 2)
	{	try
		{	d = driver.at(argv[1]);
			return d();
		}
		catch(std::exception e)
		{	usage();
			return EXIT_FAILURE;
	}	}

	//default action
	return primeTestLoop();	
}

int primeTestLoop()
{	integer i;
	integer j;
	do
	{	std::cout << "Please enter a number terminated by a carriage return (0 to quit): ";
		std::cin >> i;
		j = isPrime(i, integer(20));
		std::cout << std::endl << "the number: " << std::endl << i << std::endl;
		if(j == integer(1)) std::cout << "is prime." << std::endl;
		else std::cout << "is NOT prime.  The next prime number is: " <<std::endl << nextPrime(i, j) << std::endl;
	} while(!(i == (integer)0));
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
{       integer i = 0, j = 0, k = 0, l = 0, m = 0;
	do
	{       std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		k = i / j;
		std::cout << "i / j: " << i << "/" << j << "=" << k << std::endl;
		l = i % j;
		std::cout << "i % j: " << i << "%" << j << "=" << l << std::endl;
		m = (k*j)+l;
		assert(m==i);
	} while(!(i == integer(0)));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int equTestLoop()
{	integer  i = 0, j = 0;
	bool res;
	do
	{	std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		res = (i == j);
		std::cout << "i" << (res?"==":"!=") << "j" << std::endl;
	} while(!(i == integer(0)));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int cmpTestLoop()
{	integer i = 0, j = 0;
	bool res;
	do
	{	std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		res = (i < j);
		std::cout << "i" << (res?"":"!") << "<j" << std::endl;
		res = (i <= j);
		std::cout << "i" << (res?"":"!") << "<=j" << std::endl;
		res = (i > j);
		std::cout << "i" << (res?"":"!") << ">j" << std::endl;
		res = (i >= j);
		std::cout << "i" << (res?"":"!") << ">=j" << std::endl;
		//std::cout << std::endl;

	} while(!(i == (integer)0));
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
void usage()
{	std::cerr << "Read the README.txt" << std::endl;
}
