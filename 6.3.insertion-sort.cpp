/*
author: Robert Sedgewick
PROG: Insertion sort (improved)
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


