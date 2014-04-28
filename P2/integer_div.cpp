#include "integer.h"
#include <stack>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <utility>

integer integer::operator% (const integer D)
{	std::pair<integer, integer> ret = divide(*this, D);
	return ret.second;
}
integer integer::operator/ (const integer D)
{	std::pair<integer, integer> ret = divide(*this, D);
	return ret.first;
}
std::pair<integer, integer> integer::divide(integer R, const integer& D)
{	if(D == (integer)0) throw new std::overflow_error("Division by zero!");
	//integer R = *this;
	integer Q = 0;
	integer guess = 1;
	integer test;
	const size_t digit_max = 31;
	register unsigned int inner_loop = 0;
	std::stack<integer> stack;
	//std::stack<integer> stack2;
	if(D > R) return std::pair<integer, integer>(Q, R);
	while((guess * D) < R)
	{	stack.push(guess);
		guess = guess << (size_t)1; //bitshift it up by a whole digit
	}
	while(!stack.empty())
	{	guess = stack.top();
		stack.pop();
		assert(guess.data.back() == 1);
		guess.data.back() = guess.data.back()<<digit_max; //bitshift high digit up by 31 bits
		for(size_t i = 0; i <= digit_max; ++i)
		{	test = guess * D;
			while(test <= R)
			{	Q = Q + guess;
				R = R - test;
				test = guess * D;
			}
			++inner_loop;
			guess.data.back() = guess.data.back()>>1; //bitshift back down 1 bit.
		}
	}
	assert (R<D);
	return std::pair<integer, integer>(Q, R);
}

//std::pair<integer, integer> integer::divide(integer R, const integer& D)
//{
//
//}
