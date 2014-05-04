#include "imath.h"
#include "integer.h"
namespace imath
{
bool jacobi(const integer& x, const integer& y)
{	return imath::J(x, y);
}
bool J(const integer& x, const integer& y)
{	bool ret = true;
	long long unsigned int subProduct;
	//std::cout << "Jacobi( " << x << ", " << y << ")" << std::endl;
	if(x == (integer)1) return ret;
	else if(x.even())
	{	ret = J(x >> (size_t)1, y);
		subProduct = (long long unsigned int)(y.low_order_digits(1));
		subProduct = (subProduct*subProduct) - 1;
		subProduct = subProduct >> 3; //(/ 8)
		if(subProduct & 1ULL) ret = !ret;
	}
	else
	{	ret =  J(y%x, x);
		subProduct = (((unsigned long long int)(x.low_order_digits(1)))-1)*(((unsigned long long int)(y.low_order_digits(1)))-1);
		subProduct = subProduct >> 2; //(/4)
		if(subProduct & 1ULL) ret = !ret;
	}
	return ret;
}
}
