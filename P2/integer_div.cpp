#include "integer.h"
#include <stack>
#include <stdexcept>
#include <limits>
#include <utility>
#include <cassert>

integer integer::operator% (const integer& D) const
{	std::pair<integer, integer> ret = divide(*this, D);
	return ret.second;
}
integer integer::operator/ (const integer& D) const
{	std::pair<integer, integer> ret = divide(*this, D);
	return ret.first;
}
std::pair<integer, integer> integer::divide(integer R, const integer& D)
{	if(D == (integer)0 ) throw new std::overflow_error("Division by zero!");
	integer R_initial = R;
	integer Q = 0;
	integer guess = 1;
	integer test;
	//std::stack<integer> stack;
	size_t guess_p = 0;
	if(D > R) return std::pair<integer, integer>(Q, R);
	
	while((D << guess_p) <= R)
	{	//stack.push(guess << guess_p);
		//std::cout << (guess << guess_p) << std::endl;
		guess_p = guess_p+std::numeric_limits<unsigned int>::digits;
		//guess = guess << (size_t)std::numeric_limits<unsigned int>::digits; //bitshift it up by a whole digit
	}
	//guess = stack.top();
	//std::cout << guess << std::endl;
	
	while(guess_p < std::numeric_limits<unsigned int>::max())
	{	test = (D << guess_p);
		if(test <= R)
		{	Q = (Q + (guess << guess_p));
			R = (R - test);
		}
		--guess_p;
	}
	
	
	/*
	while(!stack.empty())
	{	guess = stack.top();
		stack.pop();
		assert(guess.data.back() == 1U);
		guess.data.back() = guess.data.back()<< (std::numeric_limits<unsigned int>::digits -1); //bitshift high digit up by 31 (nominally) bits
		for(size_t i = 0; i <= (std::numeric_limits<unsigned int>::digits - 1); ++i)
		{	test = guess * D;
			//std::cout << guess << std::endl;
			if(test <= R)
			{	Q = Q + guess;
				R = R - test;
				//test = guess * D;
			}
			guess.data.back() = guess.data.back()>>1; //bitshift back down 1 bit.
	}	}
	*/

	assert(R<D);
	Q.minimize();
	R.minimize();
	return std::pair<integer, integer>(Q, R);
}
