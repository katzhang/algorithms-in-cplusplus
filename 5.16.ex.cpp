/*
author: Kat Zhang
PROG: Write a recursive program that finds the maximum element in an array, 
based on comparing the first element in the array against the maximum element 
in the rest of the array (computed recursively)
*/

#include <iostream>

using namespace std;

int findMax(int a[], int n, int max) {
	if (n == 0) return max > a[n] ? max : a[n];
	max = max > a[n] ? max : a[n];
	return findMax(a, --n, max);
}

int main() {
	int a[] = {3, -3, 1, 3, 3};
	int m = findMax(a, 4, 0);
	cout << "max: " << m << endl;
}