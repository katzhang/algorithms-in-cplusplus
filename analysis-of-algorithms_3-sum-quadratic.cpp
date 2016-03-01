/*
author: Kat Zhang
PROG: 3-SUM in quadratic time

Design an algorithm for the 3-SUM problem that takes time proportional to N2 in the worst case. 
You may assume that you can sort the N integers in time proportional to N2 or better.

*/

#include <iostream>

using namespace std;

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
	void sort(Item a[], int left, int right) {
		for (int i = left + 1; i <= right; ++i) {
			for (int j = i; j > left; --j) {
				compexch(a[j - 1], a[j]);
			}
		}
	}

int countSum(int sortedNumbers[], int index, int left, int right) {
	int count = 0;
	int sum = -sortedNumbers[index];
	int actualSum;
	while (left < right) {
		actualSum = sortedNumbers[left] + sortedNumbers[right];
		if (actualSum < sum || left == index) {
			left++;
		} else if (actualSum > sum || right == index){
			right--;
		} else if (actualSum == sum) {
			count++;
			left++;
		}
	}
	return count;

}

int main() {

	int N;
	cin >> N;
	int numbers[N];

	for (int i = 0; i < N; ++i) {
		int n = rand() % 19 - 9; // Generate random integers between -9 and 9
		numbers[i] = n;
		cout << n << endl;
	}

	sort(numbers, 0, N - 1);

	int count = 0;

	for (int i = 0; i < N; ++i) {
		count += countSum(numbers, i, 0, N - 1);
	}

	cout << "3-Sum count: " << count << endl;

}

