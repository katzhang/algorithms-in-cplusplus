/*
author: Robert Sedgewick
PROG: Key-indexed counting
*/

#include <iostream>

using namespace std;

void discount(int a[], int left, int right) {
	int i, j, cnt[M];
	static int b[maxN];

	for (j = 0; j < M; ++j) cnt[j] = 0;
	for (i = left; i <= right; ++i) cnt[a[i] + 1]++;
	for (j = 1; j < M; ++j) cnt[j] += cnt[j - 1];
	for (i = left; i <= right; ++i) b[cnt[a[i]]++] = a[i];
	for (i = left; i <= right; ++i) a[i] = b[i];
}


