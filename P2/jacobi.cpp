#include "imath.h"
#include "integer.h"

namespace imath
{
integer J(integer& x, integer& y){
	if(x == (integer)1){
		return y;
	}
	//else if(x is even){
		//return J(x/2,y)*((-1)^(((x-1)*(y-1))/4))
	//}

	//else
	//return J( y(mod x), x)*((-1)^(((x-1)*(y-1))/4))
	return 1;
}
}
