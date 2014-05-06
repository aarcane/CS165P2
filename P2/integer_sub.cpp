#include "integer.h"
#include <stdexcept>
#include <limits>

inline void do_digit_subtraction(unsigned int, unsigned int, bool&, unsigned int&);
inline void do_digit_subtraction2(unsigned int, unsigned int, bool&, unsigned int&);


integer integer::operator-(integer y) const
{	integer x = *this;
	if(x < y) std::swap(x, y);
	integer::normalize(x,y);
	bool borrow = false;
	for(size_t i = 0; i < y.data.size() - 1; ++i)
	{	do_digit_subtraction(x.data[i], y.data[i], borrow, y.data[i]);
	}
	do_digit_subtraction2(x.data.back(), y.data.back(), borrow, y.data.back());
	y.minimize();
	return y;
}

static const long long unsigned int borrow_bit = (long long unsigned int)std::numeric_limits<unsigned int>::max() + 1ULL;
void do_digit_subtraction(unsigned int x, unsigned int y, bool& borrow, unsigned int& result)
{	long long unsigned int tmp = 0;
	tmp = borrow_bit | x;
	//if(borrow == true) --tmp;
	tmp -= borrow;
	borrow = false;
	tmp = tmp - y;
	result = tmp & std::numeric_limits<unsigned int>::max();
	borrow = ((tmp & borrow_bit) == 0);
}

void do_digit_subtraction2(unsigned int x, unsigned int y, bool& borrow, unsigned int& result)
{	result = x;
	if(borrow) --result;
	result -= y;
}

