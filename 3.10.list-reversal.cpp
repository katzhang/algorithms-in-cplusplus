/*
author: Robert Sedgewick
PROG: List reversal
*/

#include <iostream>

using namespace std;

struct node {
	int item;
	node* next;

	// Constructor
	node(int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node* nodeLink;

nodeLink reverse(nodeLink x) {
	nodeLink t, y = x, r = 0;
	while (y != 0) {
		t = y->next;
		y->next = r;
		r = y;
		y = t;
	}
	return r;
}

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]);
	nodeLink first = new node(1, 0);
	nodeLink x = first;
	nodeLink last;
	for (i = 2; i <= N; ++i) {
		x->next = new node(i, 0);
		x = x->next;
	}

	for (nodeLink p = first; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	// Reverse the list
	nodeLink newfirst = reverse(first);
	for (nodeLink p = newfirst; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


