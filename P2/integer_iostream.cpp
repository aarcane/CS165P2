#include "integer.h"
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const integer& i)
{	//assume i fits in ULL for now...
	os << "(";
	for(size_t j = i.data.size()-1; j > 0; --j) os << i.data[j] << ", ";
	os << i.data[0] << ")";
	return os;
}

std::istream& operator>>(std::istream& is, integer& i)
{	char c = 0;
	integer r = 0;
	bool success = false;
	is.get(c);
	while(c <= '9' && c >= '0')
	{	success = true;
		c -= '0';
		r = (r*(integer)10)+(integer)c;
		is.get(c);
	}
	if(!success) is.setstate(std::ios_base::failbit);
	i = r;
	return is;
}
