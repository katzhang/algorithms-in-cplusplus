/*
author: Robert Sedgewick
PROG: Adjacency-list graph representation
*/

#include <iostream>

using namespace std;

static const int V = 100;

struct node {
	int v;
	node* next;
	node(int x, node* t) {
		v = x;
		next = t;
	}
};

typedef node* nodeLink;

int main() {
	int i, j;
	nodeLink adj[V];
	for ( i = 0; i < V; ++i) {
		adj[i] = 0;
	}

	while (cin >> i >> j) {
		adj[j] = new node(i, adj[j]);
		adj[i] = new node (j, adj[i]);
	}

}