#ifndef imath_h
#define imath_h

#include "integer.h"
namespace imath
{	//return a bool indicating the result of the jacobi function.  true if J(x,y) == 1, and false otherwise.
	bool jacobi(const integer& x, const integer& y);
	//implementation of the jacobi function.
	bool J(const integer& x, const integer& y);

	//return the factor, if found, or 1 if probably prime.
	integer isPrime(const integer& x, const integer& k);

	// return the first suspected prime >= x.
	const size_t nextPrime_sieve_size = 8192;
	integer nextPrime(integer x, const integer& prime, const integer& k);
	integer nextPrime(const integer& x, const integer& k);
	
	integer b_pow_N_minus_1_mod_N(const integer& b, const integer& N);
}
#endif //imath.h
