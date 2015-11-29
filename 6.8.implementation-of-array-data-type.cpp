/*
author: Robert Sedgewick
PROG: Implementation of array data type
*/

#include <iostream>
#include "6.7.interface-for-array-data-type.h"

using namespace std;

template <class Item>
	void rand(Item a[], int N) {
		for (int i = 0; i < N; ++i) {
			rand(a[i]);
		}
	}

template <class Item>
	void scan(Item a[], int& N) {
		for (int i = 0; i < N; ++i) {
			if (!scan(a[i])) {
				break;
			}
		}
		N = i;
	}

template <class Item>
	void show(Item a[], int left, int right) {
		for (int i = left; i <= right; ++i) {
			show(a[i]);
		}
		cout << endl;
	}

