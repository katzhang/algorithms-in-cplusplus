/*
author: Robert Sedgewick
PROG: List insertion sort
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


int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	node heada(0, 0);
	nodeLink a = &heada, t = a;
	for (int i = 0; i < N; ++i) {
		t = (t->next = new node(rand() % 1000, 0));
	}
	for (nodeLink c = a; c != 0; c = c->next) {
		cout << c->item << endl;
	}
	node headb(0, 0);
	nodeLink u, x, b = &headb;
	for (t = a->next; t != 0; t = u) {
		u = t->next;
		for (x = b; x->next != 0; x = x->next) {
			if (x->next->item > t->item) break;
		}
		t->next = x->next;
		x->next = t;
	}
	for (nodeLink c = b; c != 0; c = c->next) {
		cout << c->item << endl;
	}
}


