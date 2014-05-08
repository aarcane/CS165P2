#ifndef integer_h
#define integer_h

#include <vector>
#include <iostream>

//#define LOW4 0xFFFFFFFFull
//#define HIGH4 0xFFFFFFFF00000000ull
class integer
{public:
	integer();
	integer(const integer& i);
	integer(const long long unsigned int);
	integer(const std::string& i);

	operator long long unsigned int() const;
	operator std::string() const;
	integer& operator=(const integer& i);

	// Arithmetic functions
	integer operator+(integer y) const;
	integer operator-(integer y) const;
	integer operator*(integer y) const;
	integer operator%(const integer& D) const;
	integer operator/(const integer& D) const;
	integer operator<<(const size_t& x) const;
	integer operator>>(const size_t& x) const;
	integer low_order_digits(const size_t & x) const;
	bool operator==(const integer& y) const;
	bool operator<(const integer& y) const;
	bool operator>(const integer& y) const;
	bool operator>=(const integer& y) const;
	bool operator<=(const integer& y) const;
	bool operator!=(const integer& y) const;
	integer mod(const integer& mod) const;
	integer mulmod(const integer& y, const integer& mod) const;
	integer powmod(const integer& y, const integer& mod) const;
	integer gcd(integer y) const;
	bool odd(void) const;
	bool even(void) const;
	
	// Friend iostream functions
	friend std::ostream& operator<<(std::ostream& os, const integer& out);
	friend std::istream& operator>>(std::istream& os, integer &i);

	// Other functions
	static integer random(const integer& k);
	static std::pair<integer, integer> divide(integer N, const integer& D);
	void zero();
	bool isEven();

private:
	void minimize(void);
	static void normalize(integer& x1, integer& x2);
	integer(const std::vector<unsigned int>& data);
	static integer single_digit_multiply(const integer& x, const integer& y);
	static integer long_multiply(const integer& x, const integer& y);
	static integer karatsuba(const integer& x, const integer& y);
	std::vector<unsigned int> data;
	static const long long unsigned int LOW4;
	static const long long unsigned int HIGH4;
	static const unsigned int lowBitMask[];
	static const unsigned int highBitMask[];
};

#endif //integer_h
