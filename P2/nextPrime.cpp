#include "integer.h"
#include "imath.h"

//takes in the input number and the amount to compare to.
integer nextPrime(const integer& in, const integer& k){
	while (!isPrime(in, k)){
		//if in is odd
		in=in +2;
		//else
		in = in+1;
	}
	return in;

}


/*integer nextPrime(const integer& i, const integer& prime)
{
	if(prime == integer(1)) return integer(i);
	else return integer(prime); // Not correct, but works for now!

}

integer nextPrime(const integer& i)
{	return nextPrime(i, isPrime(i, integer(20)));
}
*/