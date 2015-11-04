/*
author: Robert Sedgewick
PROG: Circular list example (Josephus problem)
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
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	nodeLink t = new node(1, 0);
	t->next = t;
	nodeLink x = t;
	for (i = 2; i <= N; ++i) {
		x = (x->next = new node(i, t));
	}
	while (x != x->next) {
		for (i = 1; i < M; ++i) {
			x = x->next;
		}
		x->next = x->next->next;
	}
	cout << x->item << endl;
}


