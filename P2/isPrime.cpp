#include "integer.h"
#include "imath.h"
#include <cassert>

namespace imath
{
//return the factor, if found, or 1 if probably prime.
integer isPrime(const integer& x, const integer& k)
{	if(x.even())
	{	if(x == (integer)2) return 1;
		else return 2;
	}
	integer b;
	for(integer i=k; i>(integer)0; i = i-(integer)1)
	{	b = integer::random(x - (integer)2) + (integer)1; // range 1 - x * 2 - x ** 3 - x
		/*std::cout << "testing possible prime x against test-witness b: x: " << x << " b: " << b << std::endl;*/
		integer gcd = b.gcd(x);
		if(!(gcd==(integer)1)) { /*std::cout << "failed GCD test" << std::endl;*/ return b;}
		else
		{	bool jac = jacobi(b, x);
			integer pow_test = b_pow_N_minus_1_mod_N(b, x);
			if( (jac && (pow_test == (integer)1)) || ( (!jac) && pow_test == x-(integer)1) ) continue;
			else { /*std::cout << "failed congruency test.  jacobi: " << (jac?"":"-") << 1 << " pow_test: " << pow_test << std::endl;*/ return b;}
		}
		return 1;
	}
	return 1; //with probability of 1-1/2^(k)
}
}
