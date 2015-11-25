/*
author: Robert Sedgewick
PROG: Recursive tree traversal
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
	if (h == 0) return;
	visit(h);
	traverse(h->l, visit);
	traverse(h->r, visit);
}