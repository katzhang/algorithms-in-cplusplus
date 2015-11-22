/*
author: Robert Sedgewick
PROG: Fibonacci numbers (recursive implementation)
*/

#include <iostream>

using namespace std;

int F(int i) {
	if (i < 1) return 0;
	if (i == 1) return 1;
	return F(i - 1) + F(i - 2);
}