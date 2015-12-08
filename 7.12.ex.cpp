/*
author: Kat Zhang
PROG: Give, in the style of Figure 5.5, the stack contents after each pair of push and pop operations, 
when Program 7.3 is used to sort a file with the keys E A S Y Q U E S T I O N
*/

#include <iostream>
#include "4.7.array-implementation-of-stack.cpp"

using namespace std;

inline void push2(STACK<int>& s, int A, int B) {
	s.push(B);
	s.push(A);
}

inline void printString(char* a, int left, int right) {
	for (int i = left; i <= right; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
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
			cout << "now the substring is: ";
			printString(a, left, right);
			if (right <= left) continue;
			int i = partition(a, left, right);
			cout << "right sub is: ";
			printString(a, i + 1, right);
			cout << "left sub is: ";
			printString(a, left, i - 1);
			push2(s, i + 1, right);
			push2(s, left, i - 1);
		}
	}


int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]);
	char* a = argv[2];

	quicksort(a, 0, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}


