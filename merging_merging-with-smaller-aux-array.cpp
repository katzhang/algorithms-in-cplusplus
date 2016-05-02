/*
author: Kat Zhang
PROG: Merging with smaller auxiliary array
Suppose that the subarray a[0] to a[N-1] is sorted and the subarray a[N] to a[2*N-1] is sorted. 
How can you merge the two subarrays so that a[0] to a[2*N-1] is sorted using an auxiliary array 
of size N (instead of 2*N)?
*/

#include <iostream>
using namespace std;

int main() {

	int N = 3;

	int array[] = {1, 22, 33, 3, 39, 40};
	int* aux = new int[N];

	int leftP, rightP, auxP, auxP2;
	leftP = auxP = 0;
	rightP = auxP2 = N;

	while (auxP <= N - 1) {
		if (array[leftP] <= array[rightP]) {
			aux[auxP++] = array[leftP++];
		} else {
			aux[auxP++] = array[rightP++];
		}
	}

	// We now have the first half of result array in aux
	// Need to merge what's left in first half to second half
	while (auxP2 <= 2*N - 1) {
		if (leftP >= N) {
			array[auxP2++] = array[rightP++];
			continue;
		}
		if (rightP >= 2*N) {
			array[auxP2++] = array[leftP++];
			continue;
		}
		if (array[leftP] <= array[rightP]) {
			array[auxP2++] = array[leftP++];
		} else {
			array[auxP2++] = array[rightP++];
		}
	}

	// Then copy aux to the first half of original array
	int p = 0;

	while (p < N) {
		array[p] = aux[p];
		p++;
	}

	for (int i = 0; i < 2*N; ++i) {
		cout << array[i] << ", ";
	}
	cout << endl;

}



