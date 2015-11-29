/*
author: Robert Sedgewick
PROG: Shellsort
*/

#include <iostream>

using namespace std;

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
	void shellsort(Item a[], int left, int right) {
		int h;
		for (h = 1; h <= (right - left) / 9; h = 3 * h + 1);
		for (; h > 0; h = h / 3) {
			for (int i = left + h; i <= right; ++i) {
				int j = i;
				Item v = a[i];
				while (j >= left + h && v < a[j - h]) {
					a[j] = a[j - h];
					j -= h;
				}
				a[j] = v;
			}
		}
	}


int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a = new int[N];
	if (sw) {
		for (i = 0; i < N; ++i) {
			a[i] = 1000 * (1.0 * rand() / RAND_MAX);
		}
	} else {
		N = 0;
		while (cin >> a[N]) {
			N++;
		}
	}
	shellsort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


