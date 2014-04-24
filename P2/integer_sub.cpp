#include "integer.h"
#include <stdexcept>

integer integer::operator-(integer y)
{	std::cout << "<operator->";
	integer x = *this;
	integer::normalize(x,y);
	if(x < y) std::swap(x, y);
	long long unsigned int borrow = 0;
	for(size_t i = 0; i < data.size(); ++i)
	{	borrow = (long long unsigned int) y.data[i] - borrow;
		borrow -= (long long unsigned int) x.data[i];
		y.data[i] = (unsigned int) (borrow & LOW4);
		borrow  =  (borrow >> 32) & 1ULL; //crop to just a single bit.
	}
	//if(borrow != 0) throw new std::underflow_error("Error subtracting.  Result would be negative.");
	//y.data.back() = (unsigned int) (carry & LOW4);
	y.minimize();
	std::cout << "</operator->";
	return y;
}
