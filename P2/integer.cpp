#include <exception>
#include <stdexcept>
#include "integer.h"

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
		data.push_back((unsigned)((i & HIGH4) >> 32));
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
	if(data.size() >= 2) ret |= ((long long unsigned int)(data[1]) << 32);
	ret |= (long long unsigned int)(data[0]);
	return ret;
}

integer& integer::operator= (const integer i)
{	zero();
	data = i.data;
	return *this;
}

bool integer::operator== (const integer y)
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

bool integer::operator< (const integer& y)
{	if(data.size()<y.data.size()) return true;
	else if(y.data.size() < data.size()) return false;
	else if(data.size() == y.data.size())
	{	auto i = data.crbegin();
		auto j = y.data.crbegin();
		while(i != data.crend())
		{	if(*i < *j) return true;
			++i;
			++j;
	}	}
	else throw new std::logic_error("some unforseen error has occured.  size comparison failed.");
	return true;
}

integer integer::operator<<(const size_t& x)
{	std::cout << "<operator<<>";
	std::cout << "sizes: (" << data.size() << ", " << x << ", " << data.size()+x << ")";
	const size_t max = (size_t)(0)-(size_t)(1);
	integer ret;
	ret.data.resize(data.size()+x, 0U);
	for(size_t i = data.size()-1; i >= 0 && i < max; --i) ret.data[i+x] = data[i];
	std::cout << "</operator<<>";
	return ret;
}

integer integer::low_order_digits(const size_t& x)
{	std::cout << "<low_order_digits>";
	integer ret(*this);
	ret.data.resize(x);
	std::cout << "</low_order_digits>";
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

bool isEven()
{
	return false;
}