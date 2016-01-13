/*
author: Robert Sedgewick
PROG: Three-way radix quicksort
*/

#include <iostream>
#define ch(A) digit(A, d)

using namespace std;

static const int maxN = 50;
static const int M = 5;

template <class Item>
void quicksortX(Item a[], int left, int right, int d) {
	int i, j, k, p, q;
	int v;

	if (right - left <= M) { 
		insertion(a, left, right);
		return;
	}
	v = char(a[r]);
	i = left - 1;
	j = right;
	p = left - 1;
	q = right;

	while (i < j) {
		while (ch(a[++i]) < v);
		while (v < ch(a[--j])) {
			if (j == left) break;
		}
		if (i > j) break;
		exch(a[i], a[j]);
		if (ch(a[i]) == v) {
			p++;
			exch(a[p], a[i]);
		}
		if (ch(a[j]) == v) {
			q--;
			exch(a[j], a[q]);
		}
	}
	if (p == q) {
		if (v != '\0') quicksortX(a, left, right, d + 1);
		return;
	}
	if (ch(a[i]) < v) i++;
	for (k = left; k <= p; k++, j--) {
		exch(a[k], a[j]);
	}
	for (k = right; k >= q; k--, i++) {
		exch(a[k], a[i]);
	}
	quicksortX(a, left, j, d);
	if ((i == right) && (ch(a[i]) == v)) i++;
	if (v != '\0') quicksortX(a, j + 1, i - 1, d + 1);
	quicksortX(a, i, r, d);
}



