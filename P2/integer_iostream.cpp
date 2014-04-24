#include "integer.h"

std::ostream& operator<<(std::ostream& os, const integer& i)
{	//assume i fits in ULL for now...
	os << (long long unsigned int)(i);
	return os;
}

std::istream& operator>>(std::istream& is, integer& i)
{	//assume we can only read in ULL for now...
	long long unsigned int j;
	is >> j;
	i = integer(j);
	return is;

}
