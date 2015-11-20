/*
author: Robert Sedgewick
PROG: Solution to the towers of Hanoi
*/

#include <iostream>

using namespace std;

void hanoi(int N, int d) {
	if (N == 0) return;
	hanoi(N - 1, -d);
	shift(N, d);
	hanoi(N - 1, -d);
}