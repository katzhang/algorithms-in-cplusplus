/*
author: Robert Sedgewick
PROG: Nonrecursive quicksort
*/

#include <iostream>
#include "4.7.array-implementation-of-stack.cpp"

using namespace std;

inline void push2(STACK<int>& s, int A, int B) {
	s.push(B);
	s.push(A);
}

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
		STACK<int> s(50);
		push2(s, left, right);
		while (!s.empty()) {
			left = s.pop();
			right = s.pop();
			if (right <= left) continue;
			int i = partition(a, left, right);
			if (i - left > right - i) {
				push2(s, left, i - 1);
				push2(s, i + 1, right);
			} else {
				push2(s, i + 1, right);
				push2(s, left, i - 1);
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
	quicksort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


