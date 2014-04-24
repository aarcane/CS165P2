#include "integer.h"

integer integer::operator*(integer y)
{	integer x = *this;
	normalize(x, y);
	x = integer::karatsuba(x, y);
	x.minimize();
	return x;
}

integer integer::karatsuba(const integer& x, const integer& y)
{	if(x.data.size() == 1)
	{	return *(new integer((long long unsigned int)(x.data[0]) * (long long unsigned int)(y.data[0])));
	}

	size_t div = x.data.size()/2;
	size_t div2 = x.data.size()-div;
	integer xlo, ylo, xhi, yhi, low, mid, high;
	xlo.data.resize(div);
	ylo.data.resize(div);
	xhi.data.resize(div2);
	yhi.data.resize(div2);
	for(size_t i = 0; i < div; ++i)
	{	xlo.data[i] = x.data[i];
		ylo.data[i] = y.data[i];
	}
	for(size_t i = 0; i < div2; ++i)
	{	xhi.data[i] = x.data[i+div];
		yhi.data[i] = y.data[i+div];
	}
	low = karatsuba(xlo, ylo);
	high = karatsuba(xhi, yhi);
	mid = (karatsuba((xlo+xhi),(ylo+yhi))-high)-low;

	div2 = div<<1;

	return (high << div2) + (mid << div) + low;
}
