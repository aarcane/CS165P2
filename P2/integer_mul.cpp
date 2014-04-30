#include "integer.h"
#include <cassert>

integer integer::operator*(integer y) const
{	integer x = *this;
	normalize(x, y);
	x = integer::karatsuba(x, y);
	x.minimize();
	return x;
}

integer integer::karatsuba(const integer& x, const integer& y)
{	assert(x.data.size() == y.data.size());

	if(x.data.size() == 1)
	{	return *(new integer((long long unsigned int)(x.data[0]) * (long long unsigned int)(y.data[0])));
	}

	//declarations
	size_t i;
	size_t div;	// = x.data.size()/2;
	size_t div2;	// = x.data.size()-div;
	integer xlo, ylo, xhi, yhi, xsum, ysum, low, mid, high;

	//initialization
	div = x.data.size()/2;
	div2 = x.data.size()-div;
	std::swap(div, div2);
	assert(x.data.size() == div+div2);
	assert(div == div2 || div == div2-1 || div == div2+1);
	xlo.data.resize(div, 0U);
	ylo.data.resize(div, 0U);
	xhi.data.resize(div2, 0U);
	yhi.data.resize(div2, 0U);
	for(i = 0; i < div; ++i)
	{	xlo.data[i] = x.data[i];
		ylo.data[i] = y.data[i];
	}
	for(i = 0; i < div2; ++i)
	{	xhi.data[i] = x.data[i+div];
		yhi.data[i] = y.data[i+div];
	}

	low = karatsuba(xlo, ylo);
	high = karatsuba(xhi, yhi);

	xsum = xlo+xhi;
	ysum = ylo+yhi;
	normalize(xsum, ysum);
	mid = karatsuba(xsum, ysum);
	//assert((high+low) < mid);
	mid = mid-(high+low);

	div2 = div * 2;
	return (high << div2) + (mid << div) + low;
}
