/*
author: Robert Sedgewick
PROG: Show how to implement a shellsort with the increments 1 8 23 77 281 1073 4193 16577 . . ., 
with direct calculations to get successive increments in a manner similar to 
the code given for Knuth's increments
*/

#include <iostream>
#include <math.h>
#define maxN 50

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
		int hs[maxN], i, h;
		hs[0] = 1;
		h = 1;
		for (i = 0; h <= (right - left) / 9; i++) {
			h = pow(4, i + 1) + 3 * pow(2, i) + 1;
			hs[i + 1] = h;
			cout << " index: " << i + 1 << " " << "h: " << h << endl;
		}
		for (int m = i + 1; m >= 0; --m) {
			for (int i = left + hs[m]; i <= right; ++i) {
				int j = i;
				Item v = a[i];
				while (j >= left + hs[m] && v < a[j - hs[m]]) {
					a[j] = a[j - hs[m]];
					j -= hs[m];
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


