#ifndef MPZ_TEST_CPP
#define MPZ_TEST_CPP

#include "integer.h"
#include <gmpxx.h>
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <bitset>

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
		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		std::cerr << x << "==" << y << "==" << copy(y) << std::endl;
		std::cerr << "====================" << std::endl;

		return false;
	}
	return true;
}

bool simpleCmpTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k -(integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		integer e = a;
		mpz_class c = copy(a);
		mpz_class d = copy(b);
		mpz_class f = c;
		std::bitset<8> resulti;
		std::bitset<8> resultm;
		resulti.reset();
		resultm.reset();

		resulti[0] = (a < b);
		resultm[0] = (c < d);
		resulti[1] = (a <= b);
		resultm[1] = (c <= d);
		resulti[2] = (a > b);
		resultm[2] = (c > d);
		resulti[3] = (a >= b);
		resultm[3] = (c >= d);

		resulti[4] = (a < e);
		resultm[4] = (c < f);
		resulti[5] = (a <= e);
		resultm[5] = (c <= f);
		resulti[6] = (a > e);
		resultm[6] = (c > f);
		resulti[7] = (a >= e);
		resultm[7] = (c >= f);

		if(resulti == resultm) continue;

		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		if(resulti[0] != resultm[0]) std::cerr << a << "<" << b << "!=" << c << "<" << d << std::endl;
		if(resulti[1] != resultm[1]) std::cerr << a << "<=" << b << "!=" << c << "<=" << d << std::endl;

		if(resulti[2] != resultm[2]) std::cerr << a << ">" << b << "!=" << c << ">" << d << std::endl;
		if(resulti[3] != resultm[3]) std::cerr << a << ">=" << b << "!=" << c << ">=" << d << std::endl;

		if(resulti[4] != resultm[4]) std::cerr << a << "<" << e << "!=" << c << "<" << f << std::endl;
		if(resulti[5] != resultm[5]) std::cerr << a << "<=" << e << "!=" << c << "<=" << f << std::endl;

		if(resulti[6] != resultm[6]) std::cerr << a << "<" << e << "!=" << c << "<" << f << std::endl;
		if(resulti[7] != resultm[7]) std::cerr << a << "<=" << e << "!=" << c << "<=" << f << std::endl;

		std::cerr << "====================" << std::endl;

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
		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		std::cerr << a << "+" << b << "=" << c << std::endl;
		std::cerr << d << "+" << e << "=" << f << std::endl;
		std::cerr << copy(f) << std::endl;
		std::cerr << "====================" << std::endl;
		return false;
	}
	return true;
}

bool simpleSubTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k-(integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		if(a < b) std::swap (a, b);
		integer c = a - b;
		mpz_class d = copy(a);
		mpz_class e = copy(b);
		mpz_class f = d - e;
		if(c == f) continue;
		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		std::cerr << a << "-" << b << "=" << c << std::endl;
		std::cerr << d << "-" << e << "=" << f << std::endl;
		std::cerr << copy(f) << std::endl;
		std::cerr << "====================" << std::endl;
		return false;
	}
	return true;
}

bool simpleBsTestLoop(integer k, const integer& max)
{	for(; k > (integer)1; k = k-(integer)1)
	{	integer a = integer::random(max);
		integer b;
		integer c;

		mpz_class d = copy(a);
		mpz_class e;
		mpz_class f;

		static const size_t bs_sizes[] = {0, 1, 2, 29, 30, 31, 32, 33, 62, 63, 64, 65, 66, 95, 96, 97, 127, 128, 129, 351, 352, 353, 383, 384, 385, 767, 768, 769};
		for(size_t i : bs_sizes)
		{	if(((integer)1 << i ) > max) continue;
			b = a << i;
			c = a << i;
			e = d << i;
			f = d << i;
			//std::cerr << i << " " << a << " " << b << " " << c << " " << d << " " << e << " " << f << std::endl;
			if(b == e && c == f) continue;
			std::cerr << "ERROR: Failed on test #" << k << std::endl;
			std::cerr << a << "<<" << i << "=" << b << std::endl;
			std::cerr << d << "<<" << i << "=" << e << std::endl;
			std::cerr << a << ">>" << i << "=" << c << std::endl;
			std::cerr << d << ">>" << i << "=" << f << std::endl;
			std::cerr << copy(e) << std::endl;
			std::cerr << copy(f) << std::endl;
			std::cerr << "====================" << std::endl;
			return false;
	}	}
	return true;
}


bool simpleMulTestLoop(integer k, const integer& max)
{	bool ret = true;
	for(; k > (integer)0; k = k - (integer)1)
	{	integer a = integer::random(max);
		integer b = integer::random(max);
		integer c = a * b;
		mpz_class d = copy(a);
		mpz_class e = copy(b);
		mpz_class f = d * e;
		if(c == f) continue;
		//return false;
		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		std::cerr << a << "*" << b << "=" << c << std::endl;
		std::cerr << d << "*" << e << "=" << f << std::endl;
		std::cerr << copy(f) << std::endl;
		std::cerr << "====================" << std::endl;
		return false;
		ret = false;
	}
	return ret;
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
		std::cerr << "ERROR: Failed on test #" << k << std::endl;
		std::cerr << a << "/" << b << "=" << ret.first << std::endl;
		std::cerr << a << "%" << b << "=" << ret.second << std::endl;
		std::cerr << c << "/" << d << "=" << e << std::endl;
		std::cerr << c << "%" << d << "=" << f << std::endl;
		std::cerr << copy(e) << std::endl;
		std::cerr << copy(f) << std::endl;
		std::cerr << "====================" << std::endl;

		return false;
	}
	return true;
}

int mpz_test_loop()
{	integer runs = 1000;
	size_t digits = 10;
	while(true)
	{	integer upper_limit = (((integer)1 << ((size_t)32 * digits))) - (integer)1;
		std::cout << "Testing with " << runs << " passes on  " << digits << " digit numbers:" << std::endl;
/*
		if(!simpleEqualityTestLoop(runs, upper_limit)) std::cerr << "Simple equality test loop failed." << std::endl;
		else std::cout << "Simple Equality Test Loop passed." << std::endl;

		if(!simpleCmpTestLoop(runs, upper_limit)) std::cerr << "Simple compare test loop failed." << std::endl;
		else std::cout << "Simple compare Test Loop passed." << std::endl;

		if(!simpleSumTestLoop(runs, upper_limit)) std::cerr << "Simple Sum Test Loop failed." << std::endl;
		else std::cout << "Simple Sum Test Loop passed." << std::endl;

		if(!simpleSubTestLoop(runs, upper_limit)) std::cerr << "Simple subtraction test loop failed." << std::endl;
		else std::cout << "Simple subtraction Test Loop passed." << std::endl;

		if(!simpleBsTestLoop(runs, upper_limit)) std::cerr << "Simple bitshift test loop failed." << std::endl;
		else std::cout << "Simple bitshift Test Loop passed." << std::endl;
*/
		if(!simpleMulTestLoop(runs, upper_limit)) {std::cerr << "Simple Mul Test Loop failed." << std::endl;}
		else std::cout << "Simple Mul Test Loop passed." << std::endl;
/*
		if(!simpleDivTestLoop(runs, upper_limit)) std::cerr << "Simple Div Test Loop failed." << std::endl;
		else std::cout << "Simple Div Test Loop passed." << std::endl;
*/
		++digits;
	}
	return EXIT_SUCCESS;
}

#endif
