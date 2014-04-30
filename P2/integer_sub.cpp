#include "integer.h"
#include <stdexcept>

integer integer::operator-(integer y) const
{	integer x = *this;
	integer::normalize(x,y);
	if(y < x) std::swap(x, y);
	//long long int borrow = 0; // borrow = 1 if last subtraction borrowed, and 0 otherwise.
	long long unsigned tmp = 0;
	for(size_t i = 0; i < data.size(); ++i)
	{	tmp = y.data[i];
		if(tmp < x.data[i])
		{	try
			{	tmp += (1ULL<<32);
				--y.data[i+1];
			}
			catch(...)
			{	throw new std::underflow_error("Error subtracting.  Result would be negative.");
			}
		}
		y.data[i] = tmp-x.data[i];

		//borrow = (long long int)(y.data[i]) - borrow;
		//borrow -= (long long int)(x.data[i]);
		//y.data[i] = (unsigned int) std::abs(borrow);
		//borrow  =  (borrow >> 32) & 1LL; //crop to just 0 or 1.
	}
	//if(borrow != 0) throw new std::underflow_error("Error subtracting.  Result would be negative.");
	y.minimize();
	return y;
}
