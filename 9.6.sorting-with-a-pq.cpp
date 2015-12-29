/*
author: Robert Sedgewick
PROG: Sorting with a priority queue
*/

#include <iostream>
#include "9.5.heap-based-priority-queue.cpp"

using namespace std;

template <class Item>
	void PQSort(Item a[], int left, int right) {
		int k;
		PQ<Item> pq(right - left + 1);
		for (k = left; k <= right; k++) {
			pq.insert(a[k]);
		}
		for (k = right; k >= left; k--) {
			a[k] = pq.getmax();
		}
	}



