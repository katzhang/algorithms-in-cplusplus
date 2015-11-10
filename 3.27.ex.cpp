/*
author: Kat Zhang
PROG: When building the list, Program 3.9 sets twice as many link values 
as it needs to because it maintains a circular list after each node is inserted. 
Modify the program to build the circular list without doing this extra work
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
	int i, N = atoi(argv[1]);
	nodeLink t, x, newNode;
	t = new node(1, 0);
	x = t;
	for (i = 2; i <= N; ++i) {
		newNode = (i == N) ? new node(i, t) : new node(i, 0);
		x = (x->next = newNode);
	}
}


