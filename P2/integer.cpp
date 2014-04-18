#include <exception>
#include <stdexcept>
#include "integer.h"

integer::integer()
{	try
	{	data.push_back(0);
		size.push_back(0);
	}
	catch(std::exception e)
	{	throw e;
	}
}
integer::~integer()
{	//delete[] data;
	//delete[] size;
}

integer::integer(long long unsigned int i)
{	try //assume ULL is 8 bytes long.
	{	data.push_back((unsigned)(i & LOW4));
		data.push_back((unsigned)((i & HIGH4) >> 32));
	}
	catch(std::exception e)
	{	throw e;
	}
}
integer::operator long long unsigned int() const
{	long long unsigned int ret = 0;
	if(data.size() > 2) throw new std::overflow_error("integer is too large to fit in long long unsigned int");
	else if(data.size() == 2) ret |= ((long long unsigned int)(data[1]) << 32);
	ret |= (long long unsigned int)(data[0]);
	return ret;
}
