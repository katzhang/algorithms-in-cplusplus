/*
author: Kat Zhang
PROG: Search in a bitonic array

An array is bitonic if it is comprised of an increasing sequence of integers followed immediately 
by a decreasing sequence of integers. 
Write a program that, given a bitonic array of N distinct integer values, determines 
whether a given integer is in the array.

*/

#include <iostream>

using namespace std;

bool binarySearch(const int* array, int left, int right, int value, bool isDescending = false) {
	if (left > right) return false; // Suppose all ints are positive
	int mid = (left + right) / 2;
	if (array[mid] == value) return true;
	if (left == right) return false;
	if (!isDescending) {
		if (value > array[mid]) {
			return binarySearch(array, mid + 1, right, value);
		} else {
			return binarySearch(array, left, mid - 1, value);
		}
	} else {
		if (value < array[mid]) {
			return binarySearch(array, mid + 1, right, value, true);
		} else {
			return binarySearch(array, left, mid - 1, value, true);
		}
	}
}

int findMaxIndex(const int* array, int n) {
	int maxIndex = 0;
	for (int i = 1; i < n; ++i) {
		if (array[maxIndex] < array[i]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}


bool searchBitonic(const int* array, int n, int value) {
	int mid = findMaxIndex(array, n); // high point
	if (array[mid] == value) return true;
	bool resultLeft, resultRight = true;
	resultLeft = binarySearch(array, 0, mid - 1, value);
	if (!resultLeft) {
		resultRight = binarySearch(array, mid + 1, n - 1, value, true);
	}
	return resultRight;

}

int main() {

	int numbers[] = {1, 3, 7, 23, 56, 100, 95, 32, 22, 10, 3};

	int testValue;
	cin >> testValue;

	bool result = searchBitonic(numbers, 11, testValue);

	cout << "result: " << testValue << " is in bitonic array: " << result << endl;

}

