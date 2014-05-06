#include "imath.h"
#include "integer.h"

namespace imath
{
integer b_pow_N_minus_1_mod_N(const integer& b, const integer& N)
{	//integer x = (N - (integer)1) / (integer)2;
	integer x = (N - (integer)1) >> (size_t)1;
	integer y = b;
	integer a = 1;
	while(x > (integer)0)
	{	if(x.odd()) a = (a*y) % N;
		y = (y*y) % N;
		//x = x / (integer)2;
		x = x >> (size_t)1;
	}
	return a;
}}
