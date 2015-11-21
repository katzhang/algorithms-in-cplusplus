/*
author: Kat Zhang
PROG: Write a recursive program to compute lg(N!)
*/

#include <iostream>
#include <math.h>

using namespace std;

double getLogNFactorial(double n) {
	if (n <= 0) return 0;
	return log(n) + getLogNFactorial(n - 1);
}

int main() {
	int n;
	while (cin >> n) {
		cout << getLogNFactorial(n) << endl;
	}
}