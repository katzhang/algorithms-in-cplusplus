/*
author: Kat Zhang
PROG: Nuts and bolts
A disorganized carpeter has a mixed pile of N nuts and N bolts. 
The goal is to find the corresponding pairs of nuts and bolts.
Each nut fits exactly one bolt and each bolt fits exactly one nut.
By fitting a nut and a bolt together, the carpenter can see which one is bigger 
(but the carpenter cannot compare two nuts or two bolts directly).
Design an algorithm for the problem that uses NlogN compares (probabilistically).
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int total = 5;

int bolts[total];
int nuts[total];

void exch(int& A, int& B) {
	int t = A;
	A = B;
	B = t;
}

int partition(int a[], int low, int high, int pivot) {
	int i = low;
	for (int j = low; j < high; j++) {
		if (a[j] < pivot) {
			exch(a[i], a[j]);
			i++;
		} else if (a[j] == pivot) {
			exch(a[j], a[high]);
			j--;
		}
	}
	exch(a[i], a[high]);
	return i;
}

void match(int nuts[], int bolts[], int low, int high) {
	if (low < high) {
		int pivot = partition(nuts, low, high, bolts[high]);
		partition(bolts, low, high, nuts[pivot]);

		match(nuts, bolts, low, pivot - 1);
		match(nuts, bolts, pivot + 1, high);
	}
}

void generatePile() {
	for (int i = 0; i < total; ++i) {
		bolts[i] = (rand() % 50);
		nuts[i] = bolts[i];
	}
}

int main() {
	generatePile();
	random_shuffle(&bolts[0], &bolts[total]);
	random_shuffle(&nuts[0], &nuts[total]);
	for (int i = 0; i < total; ++i) {
		cout << "bot: " << bolts[i] << endl;
		cout << "nut: " << nuts[i] << endl;
	}
	cout << "------------- sorted ------------------" << endl;
	match(nuts, bolts, 0, total - 1);
	for (int i = 0; i < total; ++i) {
		cout << "bot: " << bolts[i] << endl;
		cout << "nut: " << nuts[i] << endl;
	}
}