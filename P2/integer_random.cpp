#include "integer.h"
#include "dshrandom.h"
#include <limits>


#include <iostream>

#define HI2 0xFFFF0000U
#define LO2 0x0000FFFFU

integer integer::random(const integer& x)
{	integer ret = 0;
	unsigned r;
	ret.data.resize(x.data.size());
	std::vector<unsigned int>::const_reverse_iterator i = x.data.crbegin();
	std::vector<unsigned int>::reverse_iterator j = ret.data.rbegin();
	if(*i & HI2)
	{	do
		{	r = dshrandom(0);
			r = r & LO2 << 	(std::numeric_limits<unsigned int>::digits / 2);
			*j = r;
		} while(*j > *i);
	}
	do
	{	r = dshrandom(0);
		r = r & LO2;
		*j = (*j & HI2) | r;
	} while(*j > *i);
	for(++j; j != ret.data.rend(); ++j)
	{	do
		{	r = dshrandom(0);
			r = r & LO2 << (std::numeric_limits<unsigned int>::digits / 2);
			*j = r;
		} while(ret > x);
		do
		{	r = dshrandom(0);
			r = r & LO2;
			*j = (*j & HI2) | r;
		} while(ret > x);
	}
	ret.minimize();
	return ret;
	return 4; // chosen by fair dice roll, guaranteed to be random.
}
