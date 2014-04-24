#include "integer.h"
#include "imath.h"


integer nextPrime(const integer& i, const integer& prime)
{
	if(prime == integer(1)) return integer(i);
	else return integer(prime); // Not correct, but works for now!

}

integer nextPrime(const integer& i)
{	return nextPrime(i, isPrime(i, integer(20)));
}
