/*
author: Kat Zhang
PROG: Modify Program 7.1 to return if all keys in the subfile are equal. 
Compare the performance of your program to Program 7.1 for large random files 
with keys having t distinct values for t = 2, 5, and 10
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
	int partition(Item a[], int left, int right) {
		int i = left - 1, j = right, k = right - 1;
		Item v = a[right]; // Arbitarily choose rightmost element as the partition element
		bool allEqual = true;
		while (k-- > i) {
			if (a[k] != v) {
				allEqual = false;
				break;
			}
		}
		if (allEqual) return;

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
			a[i] = 1000 * (1.0 * rand() / RAND_MAX);
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


