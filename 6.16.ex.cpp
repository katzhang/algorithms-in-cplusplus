/*
author: Kat Zhang
PROG: Give an implementation of insertion sort with the inner loop coded as a while loop that terminates 
on one of two conditions, as described in the text
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
		for (int i = left + 1; i <= right; ++i) {
			int j = i;
			while (j > left && a[j] < a[j - 1]) {
				compexch(a[j - 1], a[j]);
				j--;
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
	sort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


