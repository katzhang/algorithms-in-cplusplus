/*
author: Robert Sedgewick
PROG: First-class ADT for complex numbers
*/

#include <iostream>

class Complex {
private:
	float re, im;
public:
	Complex(float x, float y) {
		re = x;
		im = y;
	}
	float Re() const {
		return re;
	}
	float Im() const {
		return im;
	}
	Complex& operator*=(const Complex& operand) {
		float tempRe = Re();
		re = Re()*rhs.Re() - Im()*rhs.Im();
		im = tempRe*rhs.Im() + Im()*rhs.Re();
		return *this;
	}
};

ostream& operator<<(ostream& t, const Complex& c) {
	t << c.Re() << " " << c.Im();
	return t;
}