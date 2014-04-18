#include <exception>
#include "integer.h"
integer::integer()
{	try
	{	data = new unsigned long long [1];
		size = new unsigned long long [1];
		data[0]=0;
		size[0]=0;
	}
	catch(std::exception e)
	{	throw e;
	}
}
integer::~integer()
{	delete[] data;
	delete[] size;
}	

