/*
author: Robert Sedgewick
PROG: Breadth-first search
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
	QUEUE<int> q(V*V);
	q.put(k);
	while (!q.empty()) {
		if (visited[k = q.get()] == 0) {
			visit(k);
			visited[k] = 1;
			for (nodeLink t = adj[k]; t != 0; t = t->next) {
				if (visited[t->v] == 0) {
					q.put(t->v);
				}
			}
		}
	}
}