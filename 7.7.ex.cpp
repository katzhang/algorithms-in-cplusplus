/*
author: Kat Zhang
PROG: Write a program to compute the exact value of CN, and compare 
the exact value with the approximation 2N ln N, for N = 103, 104, 105,and 106
*/

#include <iostream>

using namespace std;

int comparison = 0;

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
	int partition(Item a[], int left, int right) {
		int i = left - 1, j = right;
		Item v = a[right]; // Arbitarily choose rightmost element as the partition element
		for (;;) {
			comparison++;
			while (a[++i] < v) {
				comparison++;
			}
			comparison++;
			while (a[--j] > v) {
				if (j == left) break;
				comparison++;
			}
			comparison++;
			if (i >= j) break;
			exch(a[i], a[j]);
		}
		exch(a[i], a[right]);
		return i;
	}
template <class Item>
	void quicksort(Item a[], int left, int right) {
		comparison++;
		if (right <= left) return;
		int i = partition(a, left, right);
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}

int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a = new int[N];
	if (sw) {
		for (i = 0; i < N; ++i) {
			// a[i] = 1000 * (1.0 * rand() / RAND_MAX);
			a[i] = rand() % 2;
		}
	} else {
		N = 0;
		while (cin >> a[N]) {
			N++;
		}
	}
	quicksort(a, 0, N - 1);
	cout << "comparison: " << comparison << endl;
	cout << endl;
}


