#include "integer.h"
#include <exception>
#include <stdexcept>
#include <limits>

const unsigned int integer::lowBitMask[] = {0x0U,	0x00000001U,	0x00000003U,	0x00000007U,	0x0000000FU,
							0x0000001FU,	0x0000003FU,	0x0000007FU,	0x000000FFU,
							0x000001FFU,	0x000003FFU,	0x000007FFU,	0x00000FFFU,
							0x00001FFFU,	0x00003FFFU,	0x00007FFFU,	0x0000FFFFU,
							0x0001FFFFU,	0x0003FFFFU,	0x0007FFFFU,	0x000FFFFFU,
							0x001FFFFFU,	0x003FFFFFU,	0x007FFFFFU,	0x00FFFFFFU,
							0x01FFFFFFU,	0x03FFFFFFU,	0x07FFFFFFU,	0x0FFFFFFFU,
							0x1FFFFFFFU,	0x3FFFFFFFU,	0x7FFFFFFFU,	0xFFFFFFFFU
};
const unsigned int integer::highBitMask[] = {0x0U,	0x80000000U,	0xC0000000U,	0xE0000000U,	0xF0000000U,
							0xF8000000U,	0xFC000000U,	0xFE000000U,	0xFF000000U,
							0xFF800000U,	0xFFC00000U,	0xFFE00000U,	0xFFF00000U,
							0xFFF80000U,	0xFFFC0000U,	0xFFFE0000U,	0xFFFF0000U,
							0xFFFF8000U,	0xFFFFC000U,	0xFFFFE000U,	0xFFFFF000U,
							0xFFFFF800U,	0xFFFFFC00U,	0xFFFFFE00U,	0xFFFFFF00U,
							0xFFFFFF80U,	0xFFFFFFC0U,	0xFFFFFFE0U,	0xFFFFFFF0U,
							0xFFFFFFF8U,	0xFFFFFFFCU,	0xFFFFFFFEU,	0xFFFFFFFFU
};

integer::integer()
{	data.push_back(0U);
}

integer::~integer()
{	zero();
}

integer::integer(const integer& i)
{	data = i.data;
}

integer::integer(long long unsigned int i)
{	try //assume ULL is 8 bytes long.
	{	data.push_back((unsigned)(i & LOW4));
		data.push_back((unsigned)((i & HIGH4) >> std::numeric_limits<unsigned int>::digits));
	}
	catch(std::exception e)
	{	throw e;
	}
	minimize();
}

integer::integer(const std::vector<unsigned int>& data)
{	this->data = data;
	minimize();
}

integer::operator long long unsigned int() const
{	long long unsigned int ret = 0;
	if(data.size() >= 2) ret |= ((long long unsigned int)(data[1]) << std::numeric_limits<unsigned int>::digits);
	ret |= (long long unsigned int)(data[0]);
	return ret;
}

integer& integer::operator= (const integer& i)
{	zero();
	data = i.data;
	return *this;
}

bool integer::operator==(const integer& y) const
{	if(data.size() != y.data.size()) return false;
	auto i = data.cbegin();
	auto j = y.data.cbegin();
	while(i != data.cend())
	{	if(*i != *j) return false;
		++i;
		++j;
	}
	return true;
}

bool integer::operator< (const integer& y) const
{	if(data.size()<y.data.size()) return true;
	else if(y.data.size() < data.size()) return false;
	else if(data.size() == y.data.size())
	{	std::vector<unsigned>::const_reverse_iterator i = data.crbegin();
		std::vector<unsigned>::const_reverse_iterator j = y.data.crbegin();
		while(i != data.crend())
		{	if(*i < *j) return true;
			else if (*i > *j) return false;
			++i;
			++j;
		}
		return false;	
	}
	throw new std::logic_error("some unforseen error has occured.  size comparison failed.");
}

bool integer::operator>(const integer& y) const
{       if(data.size()>y.data.size()) return true;
	else if(y.data.size() > data.size()) return false;
	else if(data.size() == y.data.size())
	{       std::vector<unsigned>::const_reverse_iterator i = data.crbegin();
		std::vector<unsigned>::const_reverse_iterator j = y.data.crbegin();
		while(i != data.crend())
		{       if(*i > *j) return true;
			else if(*i < *j) return false;
			++i;
			++j;
		}
		return false;
	}
	throw new std::logic_error("some unforseen error has occured.  size comparison failed.");
}

bool integer::operator<=(const integer& y) const
{	return(!(*this > y));
}

bool integer::operator>=(const integer& y) const
{	return(!(*this < y));
}

bool integer::operator!=(const integer& y) const
{	return !(*this == y);
}

/*
integer integer::operator<<(const size_t& x) const
{	if(x == 0) return *this;
	const size_t max = std::numeric_limits<size_t>::max();
	integer ret;
	ret.data.resize(data.size()+x, 0U);
	for(size_t i = data.size()-1; i < std::numeric_limits<size_t>::max() && i < max; --i) ret.data[i+x] = data[i];
	return ret;
}
*/

integer integer::operator<<(const size_t& x) const
{	if(x == 0) return *this;
	const size_t i = x % std::numeric_limits<unsigned int>::digits;
	const size_t j = x / std::numeric_limits<unsigned int>::digits;
	integer ret;
	//unsigned int low_bits;
	if(i > 0) ret.data.resize(data.size()+j+1);
	else ret.data.resize(data.size()+j+1);
	//low_bits = 0;
	//std::cout << "test" << std::endl;
	for(size_t k = 0; k < data.size(); ++k)
	{	ret.data[k+j] |=(data[k]<<i);
		ret.data[k+j+1] = (data[k] & highBitMask[i]) >> (std::numeric_limits<unsigned int>::digits - i);
		//std::cout << ret << std::endl;
	}
	//ret.data.back() = ret.data.back()|low_bits;
	ret.minimize();
	return ret;
}

integer integer::operator>>(const size_t& x) const
{	if(x == 0) return *this;
	const size_t i = x % std::numeric_limits<unsigned int>::digits;
	const size_t j = x / std::numeric_limits<unsigned int>::digits;
	integer ret;
	ret.data.resize(data.size()-j, 0U);
	try
	{	for(size_t k = 0; k < ret.data.size(); ++k)
		{	ret.data[k] = data[k+j] >> x;
			ret.data[k] = (((data.at(k+j+1) & lowBitMask[i]) << (std::numeric_limits<unsigned int>::digits - i)) & highBitMask[i]) | ret.data[k];
		}
	}
	catch (std::out_of_range e){}
	catch(std::overflow_error e){}
	ret.minimize();
	return ret;
}

bool integer::odd(void) const
{	return (data[0] & 1U);
}
bool integer::even(void) const
{	return !odd();
}

integer integer::gcd(integer y) const
{	integer x = *this;
	if(x == y) return x;
	else if (x == (integer)1 || y == (integer)1) return (integer)1;
	else if (x == (integer)0) return y;
	else if (y == (integer)0) return x;
	else
	{	if(x > y) std::swap(y, x);
		return x.gcd(y%x);
	}
}

integer integer::low_order_digits(const size_t& x) const
{	if(x >= data.size()) return *this;
	integer ret(*this);
	ret.data.resize(x);
	return ret;
}

void integer::zero()
{
	#ifdef INTEGER_CRYPTO
	for(size_t i = data.size(); i >= 0; --i) data[i] = 0;
	data.resize(0);
	#endif //INTEGER_CRYPTO
}

void integer::normalize(integer& x1, integer& x2)
{	size_t newsize = std::max(x1.data.size(), x2.data.size());
	x1.data.resize(newsize, 0U);
	x2.data.resize(newsize, 0U);
}

void integer::minimize()
{	size_t i = data.size();
	while( i > 1 && data[i-1] == 0) --i;
	data.resize(i);
}
