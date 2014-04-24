#include "integer.h"
#include "imath.h"

//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k)
{	

	//if x is even
	return false;
	//else 
	//get numeric value of k
	for(int i=0; i<k; i++){
		//if(GCD(random value , x) && J(random value, x) is the same as (random value^((x-1)/2))(modN)
			//continue loop
		//else return false
	}
	return true; //with probability of 1-(2^-k)
}


// return the first suspected prime >= x.
//integer nextPrime(integer x, integer prime);
//integer nextPrime(integer x);
