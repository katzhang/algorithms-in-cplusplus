/*
author: Kat Zhang
PROG: Write a code fragment that determines the number of nodes that 
are between the nodes referenced by two given pointers x and t to nodes on a circular list
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

int getNumberOfNodesBetween(nodeLink x, nodeLink y) {
	int i = 0;
	nodeLink current = x->next;
	while (current != y) {
		++i;
		current = current->next;
	}
	return i;
}

int main(int argc, char *argv[]) {
	int i, count, N = atoi(argv[1]);
	nodeLink t = new node(1, 0);
	t->next = t;
	nodeLink x = t;
	nodeLink y, z;
	for (i = 2; i <= N; ++i) {
		if (i == 9) {
			y = new node(i, t);
			x = (x->next = y);
		} else if (i == 3) {
			z = new node(i, t);
			x = (x->next = z);
		} else {
			x = (x->next = new node(i, t));
		}
	}
	count = getNumberOfNodesBetween(z, y);
	cout << count << endl;
}


