#include "integer.h"
#include "imath.h"
<<<<<<< HEAD
#include "randGen.h"

//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k)
{	
	integer temp = x;
	if (temp.isEven()){
		return false;
	}
=======
#include <cassert>
namespace imath
{
//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k)
{	
	assert(x != k);
	//if x is even
	return false;
>>>>>>> 1b9595e387f4c28f0276f71cb77e1c8d0e926390
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
	return x == k; //with probability of 1-(2^-k)
}
}
