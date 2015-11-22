/*
author: Robert Sedgewick
PROG: Knapsack problem (recursive implementation)
*/

#include <iostream>

using namespace std;

typedef struct {
	int size;
	int val;
} Item;

int knap(int cap) {
	int i, space, max, t;
	for (i = 0, max = 0; i < N; ++i) {
		if ((space = cap_items[i].size) >= 0) {
			if ((t = knap(space) + items[i].val) > max) {
				max = t;
			}
		}
	}
	return max;
}