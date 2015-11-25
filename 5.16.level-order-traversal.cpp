/*
author: Robert Sedgewick
PROG: Level-order traversal (nonrecursive)
*/

#include <iostream>

using namespace std;

struct node {
	Item item;
	node* l, r;
	node(Item x) {
		item = x;
		l = 0;
		r = 0;
	};
};

typedef node* nodeLink;

void traverse(nodeLink h, void visit(nodeLink)) {
	QUEUE<nodeLink> q(max);
	q.push(h);
	while (!q.empty()) {
		visit(h = q.pop());
		if (h->r != 0) {
			q.push(h->r);
		}
		if (h->l != 0) {
			q.push(h->l);
		}
	}
}