/*
author: Robert Sedgewick
PROG: Recursive tree traversal (adjacency list graph)
*/

#include <iostream>

using namespace std;

struct node {
	int v;
	node* next;
	node(int x, node* t) {
		v = x;
		next = t;
	}
};

typedef node* nodeLink;

nodeLink* visited;

void traverse(int k, void visit(int)) {
	visit(k);
	visited[k] = 1;
	for (nodeLink t = adj[k]; t != 0; t = t->next) {
		if (!visited[t->v]) {
			traverse(t->v, visit);
		}
	}
}