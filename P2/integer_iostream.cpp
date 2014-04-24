#include "integer.h"
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const integer& i)
{	//assume i fits in ULL for now...
	os << (long long unsigned int)(i) << " size: " << i.data.size();
	return os;
}

std::istream& operator>>(std::istream& is, integer& i)
{	//std::stringstream s;
	//unsigned char c = '0';
	//assume we can only read in ULL for now...
	long long unsigned int j = 0;
	//while(is.peek() <= '9' && is.peek() >= '0')
	//{	is >> c;
	//	s << c;
	//}
	//is >> c;
	//std::cout << "=====" << std::endl << "DEBUG: '" << s.str() <<"' ";
	//s >> j;
	is >> j;
	//std::cout << "'" << j <<"'" << std::endl << std::endl;
	//is >> j;
	i = integer(j);
	return is;

}
