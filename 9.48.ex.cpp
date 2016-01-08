/*
author: Kat Zhang
PROG: Suppose that an array is filled with the keys E A S Y Q U E S T I O N. 
Give the contents of the pq and qp arrays after these keys are inserted into an 
initially empty heap using Program 9.12.
*/

#include <iostream>
#include "9.12.index-heap-based-pq.cpp"

using namespace std;

int main() {
	// char str[] = {"EASYQUESTION"};
	int str[] = {10, 2, 8, 9, 5, 6, 12, 3, 4, 1, 11, 7};
	PQ<int> pq(12);
	for (int i = 0; i < 12; ++i) {
		pq.insert(str[i]);
	}
	while (!pq.empty()) {
		cout << "get max: " << pq.getmax() << endl;
	}
}



