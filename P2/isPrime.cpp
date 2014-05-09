#include "integer.h"
#include "imath.h"
#include <cassert>

namespace imath
{
//return the factor, if found, or 1 if probably prime.
/*
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
			if(GCD(random , x) == (integer)1 && J(random, x) == temp.mod(x)){
					//continue loop
			}
			else{
				return false;
			}
		}
*/
integer isPrime(const integer& x, const integer& k)
{	if(x.even())
	{	if(x == (integer)2) return 1;
		else return 2;
	}
	integer b;
	for(integer i=k; i>(integer)0; i = i-(integer)1)
	{	b = integer::random(x - (integer)2) + (integer)1; // range 1 - x
		//std::cout << "testing possible prime x against test-witness b: x: " << x << " b: " << b << std::endl;
		integer gcd = b.gcd(x);
		if(gcd!=(integer)1) { /*std::cout << "failed GCD test" << std::endl;*/ return b;}
		else
		{	bool jac = jacobi(b, x);
			integer pow_test = b_pow_N_minus_1_mod_N(b, x);
			if( (jac && (pow_test == (integer)1)) || ( (!jac) && pow_test == x-(integer)1) ) continue;
			else { /* std::cout << "failed congruency test.  jacobi: "  << (jac?"":"-") << 1 << " pow_test: " << pow_test << std::endl;*/ return b;}
		}
	}
	return 1; //with probability of 1-1/2^(k)
}
}
