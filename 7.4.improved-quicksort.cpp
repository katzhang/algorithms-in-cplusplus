/*
author: Robert Sedgewick
PROG: Improved quicksort
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
	void insertion(Item a[], int left, int right) {
		int i;
		for (i = right; i > left; --i) {
			compexch(a[i - 1], a[i]); // Set the sentinel
		}
		for (i = left + 2; i <= right; ++i) {
			int j = i;
			Item v = a[i];
			while (v < a[j - 1]) {
				a[j] = a[j - 1];
				j--;
			}
			a[j] = v;
		}
	}

template <class Item>
	int partition(Item a[], int left, int right) {
		int i = left - 1, j = right;
		Item v = a[right]; // Arbitarily choose rightmost element as the partition element
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
		if (right - left <= M) return;
		exch(a[left + right / 2], a[right - 1]); // exchange middle with second to last
		compexch(a[left], a[right - 1]);
		compexch(a[left], a[right]);
		compexch(a[right - 1], a[right]);
		int j, N = right - left + 1;
		for (j = 0; j < N; ++j) {
			cout << a[j] << " ";
		}
		cout << endl;
		int i = partition(a, left + 1, right - 1);
		quicksort(a, left, i - 1);
		quicksort(a, i + 1, right);
	}
template <class Item>
	void hybridsort(Item a[], int left, int right) {
		quicksort(a, left, right);
		insertion(a, left, right);
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
	hybridsort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


