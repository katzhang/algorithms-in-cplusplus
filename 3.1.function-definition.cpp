/*
author: Robert Sedgewick
PROG: Function definition.
*/

#include <iostream>

using namespace std;

int lg(int);

int main() {
	for (int N = 1000; N <= 1000000000; N *= 10) {
		cout << lg(N) << " " << N << endl;
	}

}

int lg(int N) {
	int i = 0;
	for (i = 0; N > 0; i++, N /= 2);
	return i;
}