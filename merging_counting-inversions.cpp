/*
author: Kat Zhang
PROG: Counting inversions
An inversion in an array a[] is a pair of entries a[i] and a[j] such that i<j but a[i]>a[j]. 
Given an array, design a linearithmic algorithm to count the number of inversions.
https://github.com/guibin/Knowledge/blob/master/libs/lib.algorithm/src/main/java/guibin/zhang/onlinecourse/CountingInversions.java
*/

#include <iostream>
#include <time.h>
using namespace std;

int numOfInversions = 0;

int merge(int a[], int aux[], int low, int mid, int high) {
	// Copy original to aux
	for (int i = low; i <= high; ++i) {
		aux[i] = a[i];
	}

	int i = low, j = mid + 1, count = 0;
	for (int k = low; k <= high; ++k) {
		if (i > mid) {
			a[k] = aux[j++];
		} else if (j > high) {
			a[k] = aux[i++];
		} else if (aux[i] > aux[j]) {
			a[k] = aux[j++];
		    //This is the most important part to count the inversions.
            //If aux[i] > aux[j], then following items in left part are all > aux[j].
            //So for aux[j], there are totally (mid - i + 1) reversed items: aux[i], aux[i + 1], ..., aux[mid] > aux[j],
            //since at this stage, sub-array [lo, mid], [mid + 1, hi] are sorted repectively.
			count += mid - i + 1;
		} else {
			a[k] = aux[i++];
		}
	}
	return count;
}

int sort(int a[], int aux[], int low, int high) {
	if (low >= high) return 0;
	int mid = low + (high - low) / 2;
	int count1 = sort(a, aux, low, mid);
	int count2 = sort(a, aux, mid + 1, high);
	int count3 = merge(a, aux, low, mid, high);
	return count1 + count2 + count3;
}

int countInversions(int a[], int size) {
	int aux[size];
	return sort(a, aux, 0, size - 1);
}

int main() {
	srand (time(NULL));

	int ar[5];
	for (int i = 0; i < 5; ++i) {
		ar[i] = rand() % 10 + 1;
		cout << ar[i] << " ";
	}
	cout << endl;
	cout << "inversions: " << countInversions(ar, 5) << endl;
}



