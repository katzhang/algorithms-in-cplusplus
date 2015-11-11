/*
author: Kat Zhang
PROG: Write a program that frees (invokes delete with a pointer to) all the nodes 
on a given linked list
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
	for (int i = 2; i < N; ++i) {
		p->next =new node(i, 0);
		p = p->next;
	}
	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	cout << "---------------------------" << endl;

	nodeLink prev;

	for (p = head; p != 0;) {
		prev = p;
		p = p->next;
		delete prev;
	}

	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


