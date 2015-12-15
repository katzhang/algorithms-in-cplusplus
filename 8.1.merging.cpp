/*
author: Robert Sedgewick
PROG: Merging
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
	void mergeAB(Item c[], Item a[], int N, 
						   Item b[], int M) {
		for (int i = 0, j = 0, k = 0; k < M + N; k++) {
			if (i == N) {
				c[k] = b[j++];
				continue;
			}
			if (j == M) {
				c[k] = a[i++];
				continue;
			}
			c[k] = (a[i] < b[j]) ? a[i++] : b[j++];
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
	quicksort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


