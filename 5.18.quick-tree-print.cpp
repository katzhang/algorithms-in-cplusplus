/*
author: Robert Sedgewick
PROG: Quick tree-print function
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

void printnode(Item x, int h) {
	for (int i = 0; i < h; ++i) {
		cout << " ";
	}
	cout << x << endl;
}

void show(nodeLink t, int h) {
	if (t == 0) {
		printnode('*', h);
		return;
	}
	show(t->r, h + 1);
	printnode(t->item, h);
	show(t->l, h + 1);
}