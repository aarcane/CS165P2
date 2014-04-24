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
	integer(const integer& i);
	integer(const long long unsigned int);
	integer(std::string & i);

	operator long long unsigned int() const;
	integer& operator=(const integer i);

	// Arithmetic functions
	integer operator+(integer y);
	integer operator-(integer y);
	integer operator*(integer y);
	integer operator%(integer mod);
	integer operator/(integer D);
	integer operator<<(const size_t& x);
	integer low_order_digits(const size_t & x);
	bool operator==(const integer y);
	bool operator<(const integer& y);
	integer mulmod(const integer y, const integer mod);
	integer powmod(const integer y, const integer mod);
	integer gcd(const integer y);
	
	// Friend iostream functions
	friend std::ostream& operator<<(std::ostream& os, const integer &i);
	friend std::istream& operator>>(std::istream& os, integer &i);

	// Other functions
	void zero();
private:
	void minimize();
	static void normalize(integer& x1, integer& x2);
	integer(const std::vector<unsigned int>& data);	
	static integer karatsuba(const integer& x, const integer& y);
	std::vector<unsigned int> data;
};

#endif //integer_h
