/*
author: Kat Zhang
PROG: Weight quick-union solution with full path compression to connectivity problem
*/

#include <iostream>

using namespace std;

static const int N = 10000;

int main() {
	int i, j, p, q, root, id[N], sz[N];
	for (i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}

	while (cin >> p >> q) {
		for (i = p; i != id[i]; i = id[i]);

		for (j = q; j != id[j]; j = id[j]);

		if (i == j) {
			continue;
		}

		if (sz[i] < sz[j]) {
			id[i] = j;
			// Re-traverse all the objects that we just touched
			// And make them point to the new root
			for (; p != id[p]; p = id[p]) {
				id[p] = j;
			}
			sz[j] += sz[i];
		} else {
			id[j] = i;
			// Re-traverse all the objects that we just touched
			// And make them point to the new root
			for (; q != id[q]; q = id[q]) {
				id[q] = i;
			}
			sz[i] += sz[j];
		}

		cout << " " << p << " " << q << endl;
	}
}