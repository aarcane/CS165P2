#include "integer.h"
#include <sstream>
#include <iostream>
#include <stack>
#include <utility>
#include <string>

std::ostream& operator<<(std::ostream& os, const integer& out)
{	os << (std::string)out;
	#ifndef NDEBUG
	os << "(";
	for(size_t j = out.data.size()-1; j > 0; --j) os << out.data[j] << ", ";
	os << out.data[0] << ")";
	#endif
	return os;

}

integer::operator std::string() const
{
	integer o = *this;
	integer i = 1;
	integer ten = 10;
	char c;
	std::string ret = "";
	std::stack<integer> st;
	std::pair<integer, integer> div;
	do
	{	st.push(i);
		//i = i * ten;
		i = i+i+i+i+i+i+i+i+i+i;
	} while(i <= o);
	do
	{	i = st.top();
		st.pop();
		c = 0;

		if(i <= o)
		{	div = divide(o, i);
			c = (char)(unsigned long long)div.first.data[0];
			o = div.second;
		}

		//while(i <= o)
		//{	++c;
		//	o = o-i;
		//}
		ret.push_back(char(c + '0'));
	} while(!st.empty());
	return ret;
}

std::istream& operator>>(std::istream& is, integer& i)
{	char c = 0;
	std::string s = "";
	bool success = false;
	is.get(c);
	while(c <= '9' && c >= '0')
	{	success = true;
		s.push_back(c);
		is.get(c);
	}
	if(success)
	{	integer r(s);
		std::swap(r, i);
	}
	else
	{	is.setstate(std::ios_base::failbit);
	}	
	return is;
}

integer::integer(const std::string & s)
{	integer();
	integer r = 0;
	const integer ten = 10;
	for(auto c = s.cbegin(); c!=s.cend() && *c <= '9' && *c >= '0'; ++c)
	{	//*c -= '0';
		//r = (r*ten)+(integer)((*c) - '0');
		r = (r+r+r+r+r+r+r+r+r+r)+(integer)((*c) - '0');
	}	
	std::swap(data, r.data);
}
