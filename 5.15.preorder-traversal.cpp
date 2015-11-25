/*
author: Robert Sedgewick
PROG: Preorder traversal (nonrecursive)
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
	STACK<nodeLink> s(max);
	s.push(h);
	while (!s.empty()) {
		visit(h = s.pop());
		if (h->r != 0) {
			s.push(h->r);
		}
		if (h->l != 0) {
			s.push(h->l);
		}
	}
}