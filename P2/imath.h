#ifndef imath_h
#define imath_h

#include "integer.h"
namespace imath
{	//return the result of the jacobi function
	integer jacobi(integer x, integer y);

	//return the factor, if found, or 1 if probably prime.
	bool isPrime(const integer& x, const integer& k);

<<<<<<< HEAD
//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k);

// return the first suspected prime >= x.
integer nextPrime(const integer& x, const integer& prime);
integer nextPrime(const integer& x);
integer GCD(const integer& random, const integer& x);
=======
	// return the first suspected prime >= x.
	integer nextPrime(const integer& x, const integer& prime);
	integer nextPrime(const integer& x);
}
>>>>>>> 1b9595e387f4c28f0276f71cb77e1c8d0e926390
#endif //imath.h
