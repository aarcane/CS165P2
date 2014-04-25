Test prime numbers.  To run from source, do the following:

make
./isPrime

Follow the onscreen instructions.


Additional sub-module functionality testing is available as follows:

you can specify a subroutine to inspect by doing the following:

make
./isPrime cmd

Follow the onscreen instructions.

cmd is one of the following:
	div	d	division, including modulus
	mul	m	multiplication
	io	i	io samples
	add	a	addition tests
	sub	s	subtraction tests
	prime	p	primality test
	jacobi	j	jacobi function
	gcd	g	greatest common denominator
	equal	e	super simple equality test
	
