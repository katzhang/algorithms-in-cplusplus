/*
author: Robert Sedgewick
PROG: Construction of a tournament
*/

#include <iostream>

using namespace std;

struct node {
	Item item;
	node* l;
	node* r;
	node(Item x) {
		item = x;
		l = 0;
		r = 0;
	};
};

typedef node* nodeLink;

nodeLink max(Item a[], int l, int r) {
	int m = (l + r) / 2;
	nodeLink x = new node(a[m]);
	if (l == r) return x;
	x->l = max(a, l, m);
	x->r = max(a, m + 1, r);
	Item u = x->l->item, v = x->r->item;
	if (u > v) {
		x->item = u;
	} else {
		x->item = v;
	}
	return x;
}


