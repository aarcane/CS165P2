#include "integer.h"
#include "imath.h"
#include <cassert>
namespace imath
{
//return the factor, if found, or 1 if probably prime.
integer isPrime(const integer& x, const integer& k)
{	if(x.even()) return 2;
	//else 
	//get numeric value of k
	for(integer i=0; i<k; i = i+(integer)1){
		//if(GCD(random value , x) && J(random value, x) is the same as (random value^((x-1)/2))(modN)
			//continue loop
		//else return false
	}
	return x == k; //with probability of 1-(2^-k)
}
}
