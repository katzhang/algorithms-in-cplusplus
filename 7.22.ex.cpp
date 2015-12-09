/*
author: Kat Zhang
PROG: Instrument Program 7.1 to give the percentage of the comparisons used in 
partitioning files of size less than 10, 100, and 1000, and print out the percentages 
when you sort random files of N elements, for N = 103, 104, 105, and 106
*/

#include <iostream>

using namespace std;

int comparisonFor10 = 0;
int comparisonFor100 = 0;
int comparisonFor1000 = 0;
int comparisonForLarge = 0;

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
	int partition(Item a[], int left, int right, int& comparison) {
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
		if (right <= left) return;
		int i, size = right - left;
		if (size <= 10) {
			i = partition(a, left, right, comparisonFor10);
		} else if (size <= 100) {
			i = partition(a, left, right, comparisonFor100);
		} else if (size <= 1000) {
			i = partition(a, left, right, comparisonFor1000);
		} else {
			i = partition(a, left, right, comparisonForLarge);
		}
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
	}
	// cout << "before sort: ";
	// for (i = 0; i < N; ++i) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	quicksort(a, 0, N - 1);
	// cout << "after sort: ";
	// for (i = 0; i < N; ++i) {
	// 	cout << a[i] << " ";
	// }
	int sum = comparisonFor10 + comparisonFor100 + comparisonFor1000 + comparisonForLarge;
	cout << "comparison for <= 10: " << (double) comparisonFor10 / sum * 100 << endl;
	cout << "comparison for <= 100: " << (double) comparisonFor100 / sum * 100 << endl;
	cout << "comparison for <= 1000: " << (double) comparisonFor1000 / sum * 100 << endl;
	cout << "comparison for > 1000: " << (double) comparisonForLarge / sum * 100 << endl;
	cout << endl;
}


