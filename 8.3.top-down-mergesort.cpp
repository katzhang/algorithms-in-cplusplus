/*
author: Robert Sedgewick
PROG: Top-down mergesort
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
	void merge(Item a[], int left, int middle, int right) {
		int i, j;
		static Item aux[maxN];
		for (i = middle + 1; i > left; i--) {
			aux[i - 1] = a[i - 1];
		}
		for (j = middle; j < right; j++) {
			aux[right + middle - j] = a[j + 1];
		}
		for (int k = left; k <= right; ++k) {
			if (aux[j] < aux[i]) {
				a[k] = aux[j--];
			} else {
				a[k] = aux[i++];
			}
		}
	}

template <class Item>
	void mergesort(Item a[], int left, int right) {
		if (right <= left) return;
		int middle = (right - left) / 2;
		mergesort(a, left, middle);
		mergesort(a, middle + 1, right);
		merge(a, left, middle, right);
	}

int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]);
	char* a = new char[N];
	N = 0;
	while (cin >> a[N]) {
		N++;
	}
	merge(a, 0, 5, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


