#include "integer.h"
#include <exception>
#include <stdexcept>
#include <limits>

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

integer integer::operator<<(const size_t& x) const
{	if(x == 0) return *this;
	const size_t max = std::numeric_limits<size_t>::max();
	integer ret;
	ret.data.resize(data.size()+x, 0U);
	for(size_t i = data.size()-1; i < std::numeric_limits<size_t>::max() && i < max; --i) ret.data[i+x] = data[i];
	return ret;
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
