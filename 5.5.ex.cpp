/*
author: Kat Zhang
PROG: Provide a nonrecursive implementation of Euclid's algorithm
*/

#include <iostream>

using namespace std;

int gcd(int m, int n) {
	int temp;
	while (n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}
	return m;
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		cout << gcd(m, n) << endl;
	}

}