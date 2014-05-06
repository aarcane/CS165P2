#include <iostream>
#include "integer.h"
#include "imath.h"
#include <map>
#include <cassert>
#include <climits>
#include <stdexcept>
#include <limits>
#include "extra.h"
#include "mpz_test.cpp"

int primeTestLoop();
int addTestLoop();
int subTestLoop();
int mulTestLoop();
int  ioTestLoop();
int divTestLoop();
int equTestLoop();
int cmpTestLoop();
int gcdTestLoop();
int jacobiTestLoop();
int randTestLoop();
int bsTestLoop();
void usage();


int main(int argc, char** argv)
{	int (*d)();
	std::map<std::string, int (*)()> driver;
	std::string cmd;
	std::cout << std::numeric_limits<size_t>::digits << std::endl;
	std::cout << extra::hb(10000) << std::endl;
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
	driver.insert(std::pair<std::string, int(*)()>("gcd",	gcdTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("g",	gcdTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("jacobi",jacobiTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("j",	jacobiTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("rand",	randTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("r",	randTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("b",	bsTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("bitshift",bsTestLoop));
	driver.insert(std::pair<std::string, int(*)()>("mpz",	mpz_test_loop));

	//did we pass an argument?
	if(argc == 2)
	{	try
		{	d = driver.at(argv[1]);
			return d();
		}
		catch(std::overflow_error& e)
		{	std::cout << e.what();
			return EXIT_FAILURE;
		}
		catch(std::exception& e)
		{	usage();
			return EXIT_FAILURE;
		}
		catch(...)
		{	//std::cout << e.what();
			return EXIT_FAILURE;
	}	}

	//default action
	return primeTestLoop();	
}

int primeTestLoop()
{	integer i;
	integer j;
	const integer k = 20;
	do
	{	std::cout << "Please enter a number terminated by a carriage return (0 to quit): ";
		std::cin >> i;
		j = imath::isPrime(i, k);
		std::cout << std::endl << "the number: " << std::endl << i << std::endl;
		if(j == (integer)1) std::cout << "is prime." << std::endl;
		else
		{	std::cout << "is NOT prime.  " << std::endl;
			std::cout << "The next prime number is: " <<std::endl << imath::nextPrime(i, j, k) << std::endl;
		}
	} while(i != (integer)0);
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
	} while(k != (integer)0);
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
	} while(k != (integer)0);
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
	} while(k != (integer)0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int ioTestLoop()
{	integer i = 0;
	do
	{	std::cout << "Enter any number (0 to quit): ";
		std::cin >> i;
		std::cout << "your number was: " << i << std::endl;
	} while(i != (integer)0);
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
		std::cout << "Performing division...";
		k = i / j;
		l = i % j;
		std::cout << "done." << std::endl;
		std::cout << "i / j: " << i << "/" << j << "=" << k << std::endl;
		std::cout << "i % j: " << i << "%" << j << "=" << l << std::endl;
		m = (k*j)+l;
		assert(m==i);
	} while(i != (integer)0);
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
	} while(i != (integer)0);
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

	} while(i != (integer)0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int gcdTestLoop()
{       integer i = 0, j = 0, k = 0;
	do
	{       std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		std::cout << "Finding GCD..." << std::flush;
		k = i.gcd(j);
		std::cout << "done." << std::endl;
		std::cout << "GCD(i,j): GCD(" << i << "," << j << "): " << k << std::endl;
	} while(i != (integer)0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int jacobiTestLoop() 
{       integer i = 0, j = 0, l = 0;
	bool k = false;
	do      
	{       std::cout << "Please enter i: ";
		std::cin >> i;
		std::cout << "Please enter j: ";
		std::cin >> j;
		std::cout << "Finding Jacobi..." << std::endl;
		l = i.gcd(j);
		if(l == (integer)1)
		{	k = imath::jacobi(i,j);
			std::cout << "done." << std::endl;
			std::cout << "jacobi(i,j): jacobi(" << i << "," << j << "): " << (k?"":"-") << "1" << std::endl;
		}
		else
		{	std::cout << "failed." << std::endl;
			std::cout << "GCD(i,j): GCD(" << i << "," << j << "): " << l << std::endl;
		}
	} while(i != (integer)0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int randTestLoop()
{	integer i = 0, j = 0;
	bool test;
	do
	{	std::cout << "Please enter an upper bound i: ";
		std::cin >> i;
		j = integer::random(i);
		test = (j <= i);
		std::cout << "0 <= j <= i" << std::endl;
		std::cout << "i: " << i << std::endl;
		std::cout << "j: " << j << std::endl;
		if(test) std::cout << "Verified." << std::endl;
		else std::cout << "Unable to verify." << std::endl;
	} while(i != (integer)0);
	std::cout << std::endl;
	return EXIT_SUCCESS;
}

int bsTestLoop()
{       integer i = 0, j = 0;
	size_t k = 0;
        //do
        {       std::cout << "Please enter an i: ";
                std::cin >> i;
		std::cout << "Please enter a k: ";
		std::cin >> k;
                j = i >> k;
                std::cout << i << " >> " << k << " = " << j << std::endl;
		j = i << k;
		std::cout << i << " << " << k << " = " << j << std::endl;
        };// while(i != (integer)0);
        std::cout << std::endl;
        return EXIT_SUCCESS;
}

void usage()
{	std::cerr << "Read the README.txt" << std::endl;
}
