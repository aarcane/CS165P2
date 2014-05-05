#include "integer.h"
#include "imath.h"
#include "randGen.h"
#include <cassert>
namespace imath
{
//return the factor, if found, or 1 if probably prime.
bool isPrime(const integer& x, const integer& k)
{	
	assert(x != k);
	//if x is even
	integer temp = x;
	if(temp.isEven()){
		return false;
	}
	else {
		//get numeric value of k
		for(integer i=0; i<k; i = i+(integer)1){
			//I'd like to do by 3 because we wouldn't need to check everything higher (even gets rid of everything before)
			integer random = dshrandom(temp/(integer)3);
			integer temp = random^((x-(integer)1)/(integer)2);
			//if(GCD(random , x) == (integer)1 && J(random, x) == temp.mod(N)){
					//continue loop
			//}
			
			//else return false
		}
	}
	return x == k; //with probability of 1-(2^-k)
}
}