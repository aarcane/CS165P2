#include "integer.h"
#include "imath.h"
#include <bitset>

namespace imath
{
//takes in the input number and the amount to compare to.
/*integer nextPrime(const integer& in, const integer& k){
	while (!isPrime(in, k)){
		//if in is odd
		in=in +2;
		//else
		in = in+1;
	}
	return in;

}
*/

integer nextPrime(integer i, const integer& prime, const integer& k)
{	integer lowP[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	std::bitset<8192> sieve;
	integer a;
	size_t b = 0;
	if(prime == (integer)1) return i;
	if(i.even())
	{	i = i+(integer)1;
		if(isPrime(i, k) == (integer)1) return i;
	}
	do
	{	sieve.set();
		sieve.reset(0);
		for(integer p : lowP)
		{	a = i % p;
			do
			{	sieve.reset(a);
				a = a+p;
			} while(a < (integer)8192);
		}
		for(b = 0; b < 8192; ++b)
		{	if(sieve.test(b) && isPrime(i + (integer)b, k) == (integer)1) return i+(integer)b;
		}
		i = i + (integer)8192;
	} while(true);
}

integer nextPrime(const integer& i, const integer& k)
{	return nextPrime(i, isPrime(i, k));
}}
