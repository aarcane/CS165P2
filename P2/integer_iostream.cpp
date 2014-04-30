#include "integer.h"
#include <sstream>
#include <iostream>
#include <stack>
#include <utility>
std::ostream& operator<<(std::ostream& os, const integer& out)
{	integer o = out;
	integer i = 1;
	integer ten = 10;
	char c;
	std::stack<integer> st;
	std::pair<integer, integer> div;
	//while(i <= o)
	do
	{	st.push(i);
		i = i * ten;
	} while(i <= o);
	//std::stack<integer> ost = st;
	
	//do
	//{
		//i = st.top();
		//st.pop();
	//} while(i >= o);
	do
	{	i = st.top();
		c = 0;
		if(i <= o)
		{	div = i.divide(o, i);
			c = (char)(unsigned long long)div.first;
		//while(o >= i)
		//{	++c;
		//	o = o-i;
		//}
			o = div.second;
		}
		os << char(c + '0');
		//o = div.second;
		//i = st.top();
		st.pop();
	} while(!st.empty());
/*
	os << "(";
	for(size_t j = out.data.size()-1; j > 0; --j) os << out.data[j] << ", ";
	os << out.data[0] << ")";
*/
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
