#include "integer.h"
#include <cassert>
#include <limits>
#include "extra.h"

integer integer::operator*(integer y) const
{	integer x = *this;
	normalize(x, y);
	x = integer::karatsuba(x, y);
	x.minimize();
	return x;
}

integer integer::karatsuba(const integer& X, const integer& Y)
{	assert(X.data.size() == Y.data.size());

	if(X.data.size() == 1)
	{	return *(new integer((long long unsigned int)(X.data[0]) * (long long unsigned int)(Y.data[0])));
	}
	
	//declarations
	size_t i;
	size_t div;	// = x.data.size()/2;
	size_t div2;	// = x.data.size()-div;
	integer xlo, ylo, xhi, yhi, xsum, ysum, low, mid, high;

	//initialization
	integer x = X;
	integer y = Y;
	//size_t digits = extra::hb(x.data.size());
	if(extra::hb(x.data.size()) != x.data.size())
	{	x.data.resize(extra::next_pow_2(x.data.size()), 0U);
		y.data.resize(extra::next_pow_2(x.data.size()), 0U);
	}
	div = x.data.size() >> 1;
	div2 = x.data.size()-div;
	std::swap(div, div2);
	//assert(x.data.size() == div+div2);
	assert(div == div2);
	//assert(div >= div2);
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
	return (high << (div2 * std::numeric_limits<unsigned int>::digits)) + (mid << (div * std::numeric_limits<unsigned int>::digits)) + low;
}
