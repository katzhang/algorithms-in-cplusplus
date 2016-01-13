/*
author: Robert Sedgewick
PROG: Batcher's odd-even merge (nonrecursive version)
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

template <class Item>
	void exch(Item& A, Item& B) {
		Item t = A;
		A = B;
		B = t;
	}
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
	int N = right - left + 1; // Assuming N / 2 is middle - left + 1
	for (int k = N[/]2; k > 0; k /= 2) {
		for (int j = k % (N / 2); j + k < N; j += k + k) {
			for (int i = 0; i < k; i++) {
				compexch(a[left + j + i], a[left + j + k + k]);
			}
		}
	}
}



