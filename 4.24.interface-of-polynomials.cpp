/*
author: Robert Sedgewick
PROG: ADT interface for polynomials
*/

#include <iostream>

template <class Number>
class POLY {
private:
	// implementation-dependent code
public:
	POLY<Number>(Number, int);
	float eval(float) const;
	friend POLY operator+(POLY&, POLY&);
	friend POLY operator*(POLY&, POLY&);
};