#include "integer.h"
#include <cassert>
#include <limits>
integer integer::operator+(integer y) const
{	integer x = *this;
	//if(y < x) std::swap(x,y);
	integer::normalize(x,y);
	long long unsigned int carry=0;
	for(size_t i = 0; i < y.data.size(); ++i)
	{	carry += (long long unsigned int) y.data[i];
		carry += (long long unsigned int) x.data[i];
		y.data[i] = (unsigned int) (carry & LOW4);
		carry =  carry >> std::numeric_limits<unsigned int>::digits; //crop off low order 32 bits.
		assert(carry == 1ULL || carry == 0ULL);
	}
	y.data.push_back( (unsigned int) (carry & LOW4) );
	//if(carry) y.data.push_back(carry);
	y.minimize();
	return y;
}
