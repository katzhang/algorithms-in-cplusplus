/*
author: Robert Sedgewick
PROG: Array implementation of polynomial ADT
*/

#include <iostream>

template <class Number>
class POLY {
private:
	int n;
	Number* a;
public:
	POLY<Number>(Number c, int N) {
		a = new Number[N + 1];
		n = N + 1;
		a[N] = c;
		for (int i = 0; i < N; ++i) {
			a[i] = 0;
		}
	}
	float eval(float x) const {
		double t = 0.0;
		for (int i = n - 1; i >= 0; --i) {
			t = t * x + a[i];
		}
		return t;
	}
	friend POLY operator+(POLY& p1, POLY& p2) {
		POLY temp(0, p1.n > p2.n ? p1.n - 1 : p2.n - 1);
		for (int i = 0; i < p1.n; ++i) {
			temp.a[i] += p1.a[i];
		}
		for (int i = 0; i < p2.n; ++i) {
			temp.a[i] += p2.a[i];
		}
		return temp;
	}
	friend POLY operator*(POLY& p1, POLY& p2) {
		POLY temp(0, (p1.n - 1) + (p2.n - 1));
		for (int i = 0; i < p1.n; ++i) {
			for (int j = 0; j < p2.n; ++j) {
				temp.a[i + j] += p1.a[i] * p2.a[j];
			}
		}
		return temp;
	}
};