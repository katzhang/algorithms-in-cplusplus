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
void radixMSD(Item a[], int left, int right, int d) {
	int i, j, count[R + 1];
	static Item aux[maxN];
	if (d > bytesword) return;
	if (right - left <= M) {
		insertion(a, left, right);
		return;
	}
	for (j = 0; j < R; j++) {
		count[j] = 0;
	}
	for (i = left; i <= right; i++) {
		count[digit(a[i], d) + 1]++;
	}
	for (j = 1; j < R; j++) {
		count[j] += count[j - 1];
	}
	for (i = left; i <= right; i++) {
		aux[left + count[digit(a[i], d)]++] = a[i];
	}
	for (i = left; i <= right; i++) {
		a[i] = aux[i];
	}
	// radixMSD(a, left, bin(0) - 1, d + 1);
	radixMSD(a, left, left + count[0] - 1, d + 1);
	for (j = 0; j < R - 1; j++) {
		radixMSD(a, bin(j), bin(j + 1) - 1, d + 1);
	}
}



