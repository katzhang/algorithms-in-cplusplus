/*
author: Kat Zhang
PROG: Write a function that returns the number of nodes on a circular list, 
given a pointer to one of the nodes on the list
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

int getNumberOfNodes(nodeLink x) {
	int i = 0;
	while (x != x->next) {
		++i;
	}
	return i;
}

int main(int argc, char *argv[]) {
	int i, count, N = atoi(argv[1]);
	nodeLink t = new node(1, 0);
	t->next = t;
	nodeLink x = t;
	for (i = 2; i <= N; ++i) {
		x = (x->next = new node(i, t));
	}
	count = getNumberOfNodes(x);
	cout << count << endl;
}


