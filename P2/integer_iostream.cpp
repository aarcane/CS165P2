#include "integer.h"
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const integer& i)
{	os << "(";
	for(size_t j = i.data.size()-1; j > 0; --j) os << i.data[j] << ", ";
	os << i.data[0] << ")";
	return os;
}

std::istream& operator>>(std::istream& is, integer& i)
{	char c = 0;
	integer r = 0;
	const integer ten = 10;
	bool success = false;
	is.get(c);
	while(c <= '9' && c >= '0')
	{	success = true;
		c -= '0';
		r = (r*ten)+(integer)c;
		//r = (r+r+r+r+r+r+r+r+r+r)+(integer)c;
		is.get(c);
	}
	if(!success) is.setstate(std::ios_base::failbit);
	i = r;
	return is;
}
