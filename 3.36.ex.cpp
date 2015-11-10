/*
author: Kat Zhang
PROG: Implement a code fragment for a linked list that exchanges 
the positions of the nodes after the nodes referenced by two given links t and u
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
	nodeLink head = new node(1, 0);
	nodeLink p = head;
	nodeLink t, u;
	for (int i = 2; i < N; ++i) {
		p->next =new node(i, 0);
		if (i == 3) {
			t = p->next;
		} else if (i == 9) {
			u = p->next;
		}
		p = p->next;
	}
	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	cout << "---------------------------" << endl;

	nodeLink tNext = t->next;
	nodeLink uNext = u->next;
	nodeLink tPrev = 0, uPrev = 0;
	for (p = head; p != 0; p = p->next) {
		if (p->next == t) {
			tPrev = p;
		}
		if (p->next == u) {
			uPrev = p;
		}
	}

	u->next = (tNext == u) ? t : tNext;
	t->next = (uNext == t) ? u : uNext;

	if (tPrev == 0) {
		uPrev->next = (uPrev == t) ? uNext : t;
		head = u;
	} else if (uPrev == 0) {
		tPrev->next = (tPrev == u) ? tNext : u;
		head = t;
	} else {
		uPrev->next = (uPrev == t) ? uNext : t;
		tPrev->next = (tPrev == u) ? tNext : u;
	}

	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


