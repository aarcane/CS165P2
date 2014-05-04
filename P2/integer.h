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
	integer operator>>(const size_t& x) const;
	integer low_order_digits(const size_t & x) const;
	bool operator==(const integer& y) const;
	bool operator<(const integer& y) const;
	bool operator>(const integer& y) const;
	bool operator>=(const integer& y) const;
	bool operator<=(const integer& y) const;
	bool operator!=(const integer& y) const;
	integer mulmod(const integer& y, const integer& mod) const;
	integer powmod(const integer& y, const integer& mod) const;
	integer gcd(integer y) const;
	bool odd(void) const;
	bool even(void) const;
	
	// Friend iostream functions
	friend std::ostream& operator<<(std::ostream& os, const integer& out);
	friend std::istream& operator>>(std::istream& os, integer &i);

	// Other functions
	void zero(void);
	static integer random(const integer& k);
private:
	void minimize(void);
	static void normalize(integer& x1, integer& x2);
	integer(const std::vector<unsigned int>& data);
	static integer karatsuba(const integer& x, const integer& y);
	std::vector<unsigned int> data;
	static std::pair<integer, integer> divide(integer N, const integer& D);
	static const unsigned int lowBitMask[];
	/* = {0x0U,		0x00000001U,	0x00000003U,	0x00000007U,	0x0000000FU, 
								0x0000001FU,	0x0000003FU,	0x0000007FU,	0x000000FFU,
								0x000001FFU,	0x000003FFU,	0x000007FFU,	0x00000FFFU,
								0x00001FFFU,	0x00003FFFU,	0x00007FFFU,	0x0000FFFFU,
								0x0001FFFFU, 	0x0003FFFFU, 	0x0007FFFFU, 	0x000FFFFFU,
								0x001FFFFFU,	0x003FFFFFU,	0x007FFFFFU,	0x00FFFFFFU,
								0x01FFFFFFU,	0x03FFFFFFU,	0x07FFFFFFU,	0x0FFFFFFFU,
								0x1FFFFFFFU,	0x3FFFFFFFU,	0x7FFFFFFFU,	0xFFFFFFFFU
	}; */
	static const unsigned int highBitMask[];
	/* = {0x0U,	0x80000000U,	0xC0000000U,	0xE0000000U,	0xF0000000U,
								0xF8000000U,	0xFC000000U,	0xFE000000U,	0xFF000000U,
								0xFF800000U,	0xFFC00000U,	0xFFE00000U,	0xFFF00000U,
								0xFFF80000U,	0xFFFC0000U,	0xFFFE0000U,	0xFFFF0000U,
								0xFFFF8000U,	0xFFFFC000U,	0xFFFFE000U,	0xFFFFF000U,
								0xFFFFF800U,	0xFFFFFC00U,	0xFFFFFE00U,	0xFFFFFF00U,
								0xFFFFFF80U,	0xFFFFFFC0U,	0xFFFFFFE0U,	0xFFFFFFF0U,
								0xFFFFFFF8U,	0xFFFFFFFCU,	0xFFFFFFFEU,	0xFFFFFFFFU
	};*/
};

#endif //integer_h
