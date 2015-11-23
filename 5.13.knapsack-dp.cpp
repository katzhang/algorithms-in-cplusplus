/*
author: Robert Sedgewick
PROG: Knapsack problem (dynamic programming)
*/

#include <iostream>

using namespace std;

typedef struct {
	int size;
	int val;
} Item;

int knap(int M) {
	static int maxKnown[M];
	static int itemKnown[M];
	int i, space, max, maxi = 0, t;
	if (maxKnown[M] != 0) return maxKnown[M];
	for (i = 0, max = 0; i < N; ++i) {
		if ((space = cap - items[i].size) >= 0) {
			if ((t = knap(space) + items[i].val) > max) {
				max = t;
				maxi = i;
			}
		}
	}
	maxKnown[M] = max;
	itemKnown[M] = items[maxi];
	return max;
}