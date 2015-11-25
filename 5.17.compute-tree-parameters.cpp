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

int count(nodeLink h) {
	if (h == 0) return 0;
	return count(h->l) + count(h->r) + 1;
}

int height(nodeLink h) {
	if (h == 0) return -1;
	int u = height(h->l), v = height(h->r);
	if (u > v) {
		return u + 1;
	} else {
		return v + 1;
	}
}