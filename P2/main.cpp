#include <iostream>
#include "integer.h"
int main(int argc, char** argv)
{	integer i;
	integer * j;
	j = new integer();
	delete j;
	std::cout << sizeof(unsigned long long) << std::endl;
	return 0;
}
