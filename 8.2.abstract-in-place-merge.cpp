/*
author: Robert Sedgewick
PROG: Abstract in-place merge
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
	mergeAB(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


