/*
author: Robert Sedgewick
PROG: Mergesort with no copying
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

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
	void mergeAB(Item c[], Item a[], int N, Item b[], int M) {
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

template <class Item>
	void mergesortABr(Item a[], Item b[], int left, int right) {
		if (right - left <= 10) { insertion(a, left, right); return; }
		int middle = (right + left) / 2;
		mergesortABr(b, a, left, middle);
		mergesortABr(b, a, middle + 1, right);
		mergeAB(a + left, b + left, middle - left + 1, b + middle + 1, right - middle);
	}

template <class Item>
	void mergesortAB(Item a[], int left, int right) {
		static Item aux[maxN];
		for (int i = left; i <= right; i++) aux[i] = a[i];
		mergesortABr(a, aux, left, right);
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
	mergesortAB(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


