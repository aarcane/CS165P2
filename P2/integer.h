#ifndef integer_h
#define integer_h

#include <vector>
#include <iostream>

#define LOW4 0xFFFFFFFFull
#define HIGH4 0xFFFFFFFF00000000ull
class integer
{public:
	integer();
	~integer();
	integer(long long unsigned int);
	operator long long unsigned int() const;
	// Arithmetic functions
	integer operator*(const integer y);
	integer operator%(const integer mod);
	integer mulmod(const integer y, const integer mod);
	integer powmod(const integer y, const integer mod);
	integer gcd(const integer y);

	friend std::ostream& operator<<(std::ostream& os, const integer &i);
	friend std::istream& operator>>(std::istream& os, integer &i);
private:
	std::vector<unsigned int> size;
	std::vector<unsigned int> data;
};

#endif //integer_h
