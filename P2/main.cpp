#include <iostream>
#include "integer.h"
#include "imath.h"
int main(int argc, char** argv)
{	integer i;
	integer * j;
	j = new integer();
	delete j;
	std::cout << "enter an unsigned long long: ";
	std::cin >> i;
	std::cout << i;
	std::cout << std::endl;
	return 0;
}
