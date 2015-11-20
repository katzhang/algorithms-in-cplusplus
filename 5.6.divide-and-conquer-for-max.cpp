/*
author: Robert Sedgewick
PROG: Divide-and-conquer to find the maximum
*/

#include <iostream>

using namespace std;

int max(int a[], int left, int right) {
	if (left == right) return a[left];
	int middle = (left + right) / 2;
	int u = max(a, left, middle);
	int v = max(a, middle + 1, right);
	if (u > v) {
		return u;
	} else {
		return v;
	}
}
