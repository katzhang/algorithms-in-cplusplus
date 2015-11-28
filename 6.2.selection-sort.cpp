/*
author: Robert Sedgewick
PROG: Selection sort
It is the method of choice for sorting files with huge items and small keys. 
For such applications, the cost of moving the data dominates the cost of making comparisons, 
and no algorithm can sort a file with substantially less data movement than selection sort.
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
	void sort(Item a[], int left, int right) {
		for (int i = left; i < right; ++i) {
			int min = i;
			for (int j = i + 1; j <= right; ++j) {
				if (a[j] < a[min]) {
					min = j;
				}
			}
			exch(a[i], a[min]);
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
	sort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


