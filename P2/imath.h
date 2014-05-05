#ifndef imath_h
#define imath_h

#include "integer.h"
namespace imath
{	//return the result of the jacobi function
	integer jacobi(integer x, integer y);

	//return the factor, if found, or 1 if probably prime.
	bool isPrime(const integer& x, const integer& k);

	// return the first suspected prime >= x.
	integer nextPrime(const integer& x, const integer& prime);
	integer nextPrime(const integer& x);
	integer GCD(const integer& rand, const integer& x);
	integer J(const integer& x, const integer& y);
}
#endif //imath.h
