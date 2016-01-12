/*
author: Robert Sedgewick
PROG: Batcher's odd–even merge (recursive version)
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

template <class Item>
	void compexch(Item& A, Item& B) {
		if (B < A) {
			exch(A, B);
		}
	}

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

template <class Item>
void merge(Item a[], int left, int middle, int right) {
	if (right == left + 1) compexch(a[left], a[right]);
	if (right < left + 2) return;
	unshuffle(a, left, right);
	merge(a, left, (left + middle) / 2, middle);
	merge(a, middle + 1, (middle + 1 + right) / 2, right);
	shuffle(a, left, right);
	for (int i = left + 1; i < right; i += 2) {
		compexch(a[i], a[i + 1]);
	}
}



