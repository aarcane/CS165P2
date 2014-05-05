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
	integer& operator=(const integer& i);

	// Arithmetic functions
	integer operator+(integer y) const;
	integer operator-(integer y) const;
	integer operator*(integer y) const;
	integer operator%(const integer& D) const;
	integer operator/(const integer& D) const;
	integer operator<<(const size_t& x) const;
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
	integer gcd(const integer& y) const;
	
	// Friend iostream functions
	friend std::ostream& operator<<(std::ostream& os, const integer& out);
	friend std::istream& operator>>(std::istream& os, integer &i);

	// Other functions
	void zero();
	bool isEven();

private:
	void minimize();
	static void normalize(integer& x1, integer& x2);
	integer(const std::vector<unsigned int>& data);
	static integer karatsuba(const integer& x, const integer& y);
	std::vector<unsigned int> data;
	static std::pair<integer, integer> divide(integer N, const integer& D);
};

#endif //integer_h
