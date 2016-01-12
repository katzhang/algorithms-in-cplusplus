/*
author: Robert Sedgewick
PROG: Perfect shuffle and perfect unshuffle
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

template <class Item>
void shuffle(Item a[], int left, int right) {
	int i, j, m = (left + right) / 2;
	static Item aux[maxN];
	for (i = left, j = 0; i <= right; i += 2, j++) {
		aux[i] = a[left + j];
		aux[i + 1] = a[m + 1 + j];
	}
	for (i = left; i <= right; i++) {
		a[i] = aux[i];
	}
}

template <class Item>
void unshuffle(Item a[], int left, int right) {
	int i, j, m = (left + right) / 2;
	static Item aux[maxN];
	for (i = left, j = 0; i <= right; i += 2, j++) {
		aux[left + j] = a[i];
		aux[m + 1 + j] = a[i + 1];
	}
	for (i = left; i <= right; i++) {
		a[i] = aux[i];
	}
}



