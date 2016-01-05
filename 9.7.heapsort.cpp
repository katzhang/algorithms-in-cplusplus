/*
author: Robert Sedgewick
PROG: Heapsort
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
	void fixUp(Item a[], int k) {
		while (k > 1 && a[k / 2] < a[k]) {
			exch(a[k], a[k / 2]);
			k = k / 2;
		}
	}

template <class Item>
	void fixDown(Item a[], int k, int N) {
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && a[j] < a[j + 1]) {
				j++;
			}
			if (!(a[k] < a[j])) {
				break;
			}
			exch(a[k], a[j]);
			k = j;
		}
	}

template <class Item>
	void heapsort(Item a[], int left, int right) {
		int k, N = right - left + 1;
		Item *pq = a + left - 1;
		for (k = N / 2; k >= 1; k--) {
			fixDown(pq, k, N);
		}
		while (N > 1) {
			exch(pq[1], pq[N]);
			fixDown(pq, 1, --N);
		}

	}



