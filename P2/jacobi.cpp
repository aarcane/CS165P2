#include "imath.h"
#include "integer.h"

namespace imath
{
integer J(integer& x, integer& y){
	if(x == (integer)1){
		return y;
	}
	else if(x.isEven()){
		integer temp = x;
		temp=temp/(integer)2;
		return J(temp,y)*(integer)((integer)(-1)^(((x-(integer)1)*(y-(integer)1))/(integer)4));
	}
	else{
	return J( y.mod(x), x)*(integer)((-1)^(((x-(integer)1)*(y-(integer)1))/(integer)4));
	}
}
}
