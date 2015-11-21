/*
author: Kat Zhang
PROG: Write a recursive program for the Josephus problem
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

void solveJoseProb(nodeLink x, int M) {
	if (x == x->next) return;
	for (int i = 1; i < M; ++i) {
		x = x->next;
	}
	x->next = x->next->next;
	solveJoseProb(x, M);

}

int main(int argc, char *argv[]) {
	int i, N = atoi(argv[1]), M = atoi(argv[2]);
	nodeLink t = new node(1, 0);
	t->next = t;
	nodeLink x = t;
	for (i = 2; i <= N; ++i) {
		x = (x->next = new node(i, t));
	}
	solveJoseProb(x, M);
	cout << x->item << endl;
}