#ifndef imath_h
#define imath_h

#include "integer.h"

//return the result of the jacobi function
integer jacobi(integer x, integer y);

//return the factor, if found, or 1 if probably prime.
integer isPrime(const integer& x, const integer& k);

// return the first suspected prime >= x.
integer nextPrime(const integer& x, const integer& prime);
integer nextPrime(const integer& x);
#endif //imath.h
