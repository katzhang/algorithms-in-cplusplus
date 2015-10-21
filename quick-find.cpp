/*
author: Robert Sedgewick
PROG: Quick-find solution to connectivity problem
*/

#include <iostream>

using namespace std;

static const int N = 10000;

int main() {
	int i, p, q, id[N];

	for (i = 0; i < N; i++) {
		id[i] = i;
	}

	while (cin >> p >> q) {
		int t = id[p];
		// Quick find
		if (t == id[q]) {
			continue;
		}
		
		// For each union operation, we iterate the for loop N times
		// And each iteration requires at least one instruction (check if loop is finished)
		for (i = 0; i < N; i++) {
			if (id[i] == t) {
				id[i] = id[q];
			}
		}
		cout << " " << p << " " << q << endl;
	}
}