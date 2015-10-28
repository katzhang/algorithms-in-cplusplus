/*
author: Kat Zhang
PROG: Write an efficient C++ function that computes ceiling of lg lg N. Do not use a library function.
*/

#include <iostream>
#include <math.h>

using namespace std;

double getCeilingOfLgLgN(double n) {
	double m = log2(log2(n));
	cout << "log2 of log2 of " << n << ": " << m << endl;
	int result = 0;
	while (result < m) {
		++result;
	}
	return result;
};

int main() {
	int n, result;
	cin >> n;
	result = getCeilingOfLgLgN(n);
	cout << "result: " << result << endl;

}