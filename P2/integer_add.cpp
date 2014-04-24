#include "integer.h"

integer integer::operator+(integer y)
{	std::cout << "<operator+>";
	integer x = *this;
	integer::normalize(x,y);
	y.data.push_back(0U);
	long long unsigned int carry=0;
	for(size_t i = 0; i < data.size(); ++i)
	{	carry += (long long unsigned int) y.data[i];
		carry += (long long unsigned int) x.data[i];
		y.data[i] = (unsigned int) (carry & LOW4);
		carry =  carry >> 32; //crop off low order 32 bits.
	}
	y.data.back() = (unsigned int) (carry & LOW4);
	y.minimize();
	std::cout << "</operator+>";
	return y;
}
