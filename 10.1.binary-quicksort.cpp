/*
author: Robert Sedgewick
PROG: Binary quicksort
*/

#include <iostream>

using namespace std;

const int bitsword = 32;
const int bitsbyte = 8;
const int bytesword = bitsword / bitsbyte;
const int R = 1 << bitsbyte;

inline int digit(long A, int B) {
	return (A >> bitsbyte*(bytesword - B - 1)) & (R - 1);
}

template <class Item>
	void exch(Item& A, Item& B) {
		Item t = A;
		A = B;
		B = t;
	}

template <class Item>
	void quicksortB(Item a[], int left, int right, int d) {
		int i = left, j = right;
		if (right <= left || d > bitsword) return;
		while (j != i) {
			while (digit(a[i], d) == 0 && (i < j)) i++;
			while (digit(a[j], d) == 1 && (j > i)) j--;
			exch(a[i], a[j]);
		}
		if (digit(a[right],d) == 0) j++;
		quicksortB(a, left, j - 1, d + 1);
		quicksortB(a, j, right, d + 1);
	}

template <class Item>
	void sort(Item a[], int left, int right) {
		quicksortB(a, left, right, 0);
	}


int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a= new int[N];
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
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	sort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


