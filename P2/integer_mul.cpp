#include "integer.h"
#include <cassert>
#include <limits>
#include "extra.h"
#include "mpz_test.h"

/*integer integer::operator*(integer y) const
{	integer x = *this;
	normalize(x, y);
	x = integer::karatsuba(x, y);
	x.minimize();
	return x;
}
*/
integer integer::operator*(integer y) const
{	integer x = *this;
	if(y < x) std::swap(x,y);
	if(x == (integer)0) return (integer)0;
	if(x.data.size() == 1) return single_digit_multiply(x, y);
	//return long_multiply(x, y);
	return karatsuba(x, y);
	//return (integer)1;
}
integer integer::single_digit_multiply(const integer& x, const integer& y)
{	integer ret = 0;
	long long unsigned int tmp = 0;
	ret.data.resize(y.data.size()+1, 0U);
	auto i = y.data.cbegin();
	auto j = ret.data.begin();
	for(; i != y.data.cend(); ++i, ++j)
	{	tmp += (long long unsigned int)x * (long long unsigned int)(*i);
		*j = (unsigned int)(tmp & 0xFFFFFFFFULL);
		tmp >>= std::numeric_limits<unsigned int>::digits;
	}
	*j = tmp;
	assert(++j == ret.data.end());
	ret.minimize();
	return ret;
}
integer integer::long_multiply(const integer& x, const integer& y)
{	using namespace mpz_test;
	integer ret, temp, shift;
	ret = 0;
	mpz_class x2, y2, ret2, temp2, shift2;
	ret2 = 0;
	x2 = copy(x);
	y2 = copy(y);
	for(size_t i(0); i < x.data.size(); ++i)
	{	temp.data.resize(1, 0U);
		temp.data[0] = x.data[i];
		temp2 = copy(temp);
		temp = (temp * y);
		temp2 = (temp2*y2);
		assert(temp == temp2);
		assert(ret == ret2 && "Before bitshift+Sum");
		shift = temp << ((size_t)32 * i);
		shift2 = temp2 << ((size_t)32 * i);
		assert(shift == shift2);
		ret = ret + shift;
		ret2 = ret2 + shift2;
		//if(!(ret == ret2)) std::cerr << ret << "!+" << copy(ret2) << std::endl;
		assert(ret == ret2 && "After bitshift+Sum");
	}
	//ret.minimize();
	return ret;
}
integer integer::karatsuba(const integer& x, const integer& y)
{	integer xlo,xhi,ylo,yhi,low,mid1,mid2,high,tmp;
	size_t div = y.data.size() / 2; //>>1; //2

	ylo.data = std::vector<unsigned int>(y.data.cbegin(), y.data.cbegin()+div);
	yhi.data = std::vector<unsigned int>(y.data.cbegin()+div, y.data.cend());

	assert(ylo.data.size() == yhi.data.size() || (ylo.data.size()+1) == yhi.data.size());

	if(x.data.size() <= ylo.data.size())
	{	xlo.data = x.data;
		xhi = 0;
	}
	else{
		xlo.data = std::vector<unsigned int>(x.data.cbegin(), x.data.cbegin()+div);
		xhi.data = std::vector<unsigned int>(x.data.begin()+div, x.data.cend());
	}
	xlo.minimize();
	xhi.minimize();
	ylo.minimize();
	yhi.minimize();
	low = xlo*ylo;
	high = xhi*yhi;
	mid1 = (xhi+xlo)*(yhi+ylo);
	mid2 = (high + low);
	//tmp = high+low;
	assert(mid2 < mid1);
	//mid = mid - tmp;
	return (high << (div * 2 * std::numeric_limits<unsigned int>::digits)) + low + (mid1 << (div * std::numeric_limits<unsigned int>::digits)) - (mid2 << (div * std::numeric_limits<unsigned int>::digits));
	return xlo;
}

/*

integer integer::karatsuba(const integer& X, const integer& Y)
{	assert(X.data.size() == Y.data.size());
	assert(X.data.size() != 0);
	if(X.data.size() == 1)
	{	return *(new integer((long long unsigned int)(X.data[0]) * (long long unsigned int)(Y.data[0])));
	}
	
	//declarations
	size_t i;
	size_t div;	// = x.data.size()/2;
	size_t div2;	// = x.data.size()-div;
	integer xlo, ylo, xhi, yhi, xsum, ysum, low, mid, high, mod;

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
	//std::swap(div, div2);
	//assert(x.data.size() == div+div2);
	//assert(div == div2);
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
	mod = (integer)1<<(size_t)(div*2*std::numeric_limits<unsigned int>::digits);
	xsum = xlo+xhi;
	ysum = ylo+yhi;
	normalize(xsum, ysum);
	mid = karatsuba(xsum, ysum);
	//assert((high+low) <= mid);
	mid = (mid+(mod-high)+(mod-low))%mod;

	//div2 = div * 2;
	return (high << (div * 2 * std::numeric_limits<unsigned int>::digits)) + (mid << (div * std::numeric_limits<unsigned int>::digits)) + low;
}
*/
