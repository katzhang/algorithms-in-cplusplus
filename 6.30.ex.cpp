/*
author: Kat Zhang
PROG: Implement a version of bubble sort that alternates left-to-right and right-to-left 
passes through the data. This (faster but more complicated) algorithm is called shaker sort
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

int toggleFlag(int flag) {
	return (flag == 0) ? 1 : 0;
}

template <class Item>
	void shaker(Item a[], int left, int right) {
		bool sorted = false;

		while (!sorted) {
			sorted = true;
			for (int i = left; i < right; ++i) {
				if (a[i] < a[i - 1]) {
					exch(a[i - 1], a[i]);
					sorted = false;
				}
			}
			if (sorted) break;
			sorted = true;
			for (int i = right; i > left; --i) {
				if (a[i] < a[i - 1]) {
					exch(a[i - 1], a[i]);
					sorted = false;
				}
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
	shaker(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


