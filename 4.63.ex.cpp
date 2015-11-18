/*
author: Kat Zhang
PROG: Overload operators + and += to work for complex numbers (Programs 4.18 and 4.19)
*/

#include <iostream>

using namespace std;

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
	Complex& operator+(const Complex& rhs) {
		return *new Complex(Re() + rhs.Re(), Im() + rhs.Im());
	}
	Complex& operator+=(const Complex& rhs) {
		re = Re() + rhs.Re();
		im = Im() + rhs.Im();
		return *this;
	}
	Complex& operator*=(const Complex& rhs) {
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

int main() {
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3 = c1 + c2;
	cout << c3 << endl;
}



