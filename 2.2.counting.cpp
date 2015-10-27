/*
author: Robert Sedgewick
PROG: How long it takes to count to 1 billion
*/

#include <iostream>
#include <time.h>

using namespace std;

int main() {
	int N;

	cin >> N;

	clock_t startTime = clock();

	int i, j, k, count = 0;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			for (k = 0; k < N; ++k) {
				count++;
			}
		}
	}

	printf("Time taken: %.8fs\n", (double)(clock() - startTime)/CLOCKS_PER_SEC);
	return 0;
}