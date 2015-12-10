/*
author: Robert Sedgewick
PROG: Quicksort with three-way partitioning
*/

#include <iostream>

using namespace std;

static const int M = 2;

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
	int operator==(const Item& A, const Item& B) {
		return !(A < B) && !(A > B);
	}

template <class Item>
	int partition(Item a[], int left, int right) {
		int i = left - 1, j = right;
		Item v = a[right]; // Arbitarily choose rightmost element as the partition element
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v) if (j == left) break;
			if (i >= j) break;
			exch(a[i], a[j]);
		}
		exch(a[i], a[right]);
		return i;
	}

template <class Item>
	void quicksort(Item a[], int left, int right) {
		int k;
		Item v = a[right];
		if (right <= left) return;
		int i = left - 1, j = right, p = left - 1, q = right;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v) if (j == left) break;
			if (i >= j) break;
			exch(a[i], a[j]);
			if (a[i] == v) { p++; exch(a[p], a[i]); }
			if (a[j] == v) { q--; exch(a[q], a[j]); }
		}
		exch(a[i], a[right]);
		j = i - 1;
		i = i + 1;
		for (k = left; k <= p; k++, j--) exch(a[k], a[j]);
		for (k = right - 1; k >= q; k--, i++) exch(a[k], a[i]);
		quicksort(a, left, j);
		quicksort(a, i, right);
	}

int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a = new int[N];
	if (sw) {
		for (i = 0; i < N; ++i) {
			a[i] = rand() % 3;
		}
	} else {
		N = 0;
		while (cin >> a[N]) {
			N++;
		}
	}
	quicksort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


