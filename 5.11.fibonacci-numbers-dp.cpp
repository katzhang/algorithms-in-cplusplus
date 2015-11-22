/*
author: Robert Sedgewick
PROG: Fibonacci numbers (dynamic programming)
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

int F(int i) {
	static int knownF[maxN];
	if (knownF[i] != 0) return knownF[i];
	int t = i;
	if (i < 1) return 0;
	if (i > 1) t = F(i - 1) + F(i - 2);
	return knownF[i] = t;
}