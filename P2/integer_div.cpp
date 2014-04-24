#include "integer.h"
#include <stack>
#include <stdexcept>
integer integer::operator/ (integer D)
{	if(D == (integer)0) throw new std::overflow_error("Division by zero!");
	integer R = *this;
	integer Q = 0;
	integer guess = 1;
	integer test;
	const size_t digit_max = 31;
	std::stack<integer> stack;
	std::stack<integer> stack2;
	while((guess * D) < R)
	{	stack.push(guess);
		guess = guess << (size_t)1; //bitshift it up by a whole digit
	}
	while(!stack.empty())
	{	guess = stack.top();
		stack.pop();
		guess.data.back() = guess.data.back()<<digit_max;
		for(size_t i = 0; i < digit_max; ++i)
		{	test = guess * D;
			if(test < R)
			{	Q = Q + guess;
				R = R - test;
			}
			guess.data.back() = guess.data.back()>>1;
		}
	}
	return Q;
}
