#include "integer.h"
#include "imath.h"
#include "randGen.h"

//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k)
{	
	integer temp = x;
	if (temp.isEven()){
		return false;
	}
	//else 
	else{
		//get numeric value of k
		temp = dshrandom((long)&temp);
		
		for(integer i=0; i<k; i = i+(integer)1){
		//if(GCD(random , x) == (integer)1 && J(random value, x) is the same as (random value^((x-1)/2))(modN)
			//continue loop
		//else return false
		}
	}
	return true; //with probability of 1-(2^-k)
}


// return the first suspected prime >= x.
//integer nextPrime(integer x, integer prime);
//integer nextPrime(integer x);
