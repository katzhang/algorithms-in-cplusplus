/*
author: Robert Sedgewick
PROG: Adjacency-matrix graph representation
*/

#include <iostream>

using namespace std;

static const int V = 100;

int main() {
	int i, j, adj[V][V];
	for ( i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			adj[i][j] = 0;
		}
	}
	for (i = 0; i < V; ++i) {
		adj[i][i] = 1;
	}

	while (cin >> i >> j) {
		adj[i][j] = 1;
		adj[j][i] = 1;
	}

}