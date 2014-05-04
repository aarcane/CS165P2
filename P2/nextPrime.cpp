#include "integer.h"
#include "imath.h"
#include <bitset>

namespace imath
{
integer nextPrime(integer i, const integer& prime, const integer& k)
{	integer lowP[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	std::bitset<nextPrime_sieve_size> sieve;
	size_t a;
	size_t b = 0;
	if(prime == (integer)1) return i;
	do
	{	
		if(i > (integer)97)
		{	sieve.set();
			sieve.reset(0);
			for(integer p : lowP)
			{	a = p-(i % p);
				do
				{	//std::cout << "sieve removing " << (i + (integer)a) << std::endl;
					sieve.reset(a);
					a += p;
				} while(a < nextPrime_sieve_size);
			}
			for(b = 0; b < nextPrime_sieve_size; ++b)
			{	//std::cout << i + (integer)b << std::endl;
				if(sieve.test(b))
					if(isPrime(i + (integer)b, k) == (integer)1)
						return i+(integer)b;
			}
			i = i + (integer)nextPrime_sieve_size;
		}
		else
		{	for(integer p: lowP)
			{	if(p >= i) return p;
			}
			i = 98;//didn't find a next prime.  try again.  Wait, what?  this should never happen..  Anyway, moving on...
		}
	} while(true);
}

integer nextPrime(const integer& i, const integer& k)
{	return nextPrime(i, isPrime(i, k), k);
}}
