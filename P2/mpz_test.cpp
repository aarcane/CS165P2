#ifndef MPZ_TEST_CPP
#define MPZ_TEST_CPP

#include "integer.h"
#include <gmpxx.h>
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>

namespace
{
mpz_class copy(const integer& i)
{	std::string s = (std::string)i;
	mpz_class ret = (mpz_class)s;
	return ret;
}
integer copy(const mpz_class& i)
{	std::string s = i.get_str();
	integer ret = integer(s);
	return ret;
}
bool operator==(const mpz_class& a, const integer& b)
{	std::string A = a.get_str();
	std::string B = (std::string)b;
	return (A == B);
}

}
bool operator==(const integer& b, const mpz_class& a)
{	return (a == b);
}

bool simpleEqualityTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k -(integer)1)
	{	integer x = integer::random(max);
		mpz_class y = copy(x);
		if(x == y) continue;
		return false;
	}
	return true;
}
bool simpleSumTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k-(integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		integer c = a + b;
		mpz_class d = copy(a);
		mpz_class e = copy(b);
		mpz_class f = d + e;
		if(c == f) continue;
		return false;
	}
	return true;
}

bool simpleMulTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k - (integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		integer c = a * b;
		mpz_class d = copy(a);
		mpz_class e = copy(b);
		mpz_class f = d * e;
		if(c == f) continue;
		std::cout << "ERROR: " << std::endl;
		std::cout << a << "*" << b << "=" << c << std::endl;
		std::cout << d << "*" << e << "=" << f << std::endl;
		std::cout << "====================" << std::endl;
		return false;
	}
	return true;
}

bool simpleDivTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k=k-(integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		mpz_class c = copy(a);
		mpz_class d = copy(b);
		std::pair<integer, integer> ret = integer::divide(a,b);
		mpz_class e = c / d;
		mpz_class f = c % d;
		if(ret.first == e && ret.second == f) continue;
		return false;
	}
	return true;
}

int mpz_test_loop()
{	integer runs = 1000;
	integer upper_limit = ((integer)1 << (size_t) 32);
	while(true)
	{	std::cout << "Testing with runs: " << runs << " and upper_limit " << upper_limit << std::endl;
		if(!simpleEqualityTestLoop(runs, upper_limit)) std::cout << "Simple equality test loop failed." << std::endl;
		else std::cout << "Simple Equality Test Loop passed." << std::endl;
		
		if(!simpleSumTestLoop(runs, upper_limit)) std::cout << "Simple Sum Test Loop failed." << std::endl;
		else std::cout << "Simple Sum Test Loop passed." << std::endl;
	
		if(!simpleMulTestLoop(runs, upper_limit)) {std::cout << "Simple Mul Test Loop failed." << std::endl; return EXIT_FAILURE;}
		else std::cout << "Simple Mul Test Loop passed." << std::endl;
		
		if(!simpleDivTestLoop(runs, upper_limit)) std::cout << "Simple Div Test Loop failed." << std::endl;
		else std::cout << "Simple Div Test Loop passed." << std::endl;
		//runs = runs * (integer)100;
		upper_limit = upper_limit << (size_t) 32;
	}
	
	return EXIT_SUCCESS;
}

#endif
