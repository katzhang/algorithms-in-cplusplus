/*
author: Kat Zhang
PROG: Write a function that takes a link to a list as argument and returns a link to 
a copy of the list (a new list that contains the same items, in the same order)
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

nodeLink copyList(nodeLink p) {
	nodeLink newH = new node(p->item, 0);
	nodeLink copyP = newH;
	p = p->next;
	while (p != 0) {
		copyP = (copyP->next = new node(p->item, 0));
		p = p->next;
	}
	return newH;
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	nodeLink head = new node(1, 0);
	nodeLink p = head;
	for (int i = 2; i < N; ++i) {
		p->next =new node(i, 0);
		p = p->next;
	}
	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	cout << "---------------------------" << endl;

	nodeLink newH = copyList(head);

	for (p = newH; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


