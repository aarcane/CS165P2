#include <iostream>
#include "integer.h"
#include "imath.h"
int main(int argc, char** argv)
{	integer i;
	integer * j;
	j = new integer( 100001 );
	//delete j;
	do
	{	std::cout << "Please enter a number terminated by a carriage return (0 to quit): ";
		std::cin >> i;
		//j = new integer();
		//*j = i;
		*j = isPrime(i, integer(20));
		std::cout << std::endl << "the number: " << std::endl << i << std::endl;
		if(*j == integer(1)) std::cout << "is prime." << std::endl;
		else std::cout << "is NOT prime.  The next prime number is: " <<std::endl << nextPrime(i, *j) << std::endl;
		//if(*j == i) std::cout << "==";
		//else std::cout << "!=";
		//std::cout << " " << i;
		//std::cout << std::endl;
		//delete j;
	} while(i != 0);
	delete j;
	return 0;
}
