#ifndef imath_h
#define imath_h

#include "integer.h"

//return the result of the jacobi function
integer jacobi(integer x, integer y);

//return the factor, if found, or 1 if probably prime.
integer isPrime(integer x, integer k);

// return the first suspected prime >= x.
integer nextPrime(integer x, integer prime);
integer nextPrime(integer x);
#endif //imath.h
