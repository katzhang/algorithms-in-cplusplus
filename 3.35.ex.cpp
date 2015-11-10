/*
author: Kat Zhang
PROG:Write a function that rearranges a linked list to put the nodes 
in even positions after the nodes in odd positions in the list, 
preserving the relative order of both the evens and the odds
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

nodeLink rearrange(nodeLink h) {
	nodeLink p;
	nodeLink newH = new node(h->item, 0);
	nodeLink p2 = newH;
	for (p = h; p != 0; p = p->next->next) {
		if (p == h) {
			p2 = newH;
		} else {
			p2 = (p2->next = new node(p->item, 0));
		}
		if (p->next == 0) break;
	}
	for (p = h->next; p != 0; p = p->next->next) {
		p2 = (p2->next = new node(p->item, 0));
		if (p->next == 0) break;
	}
	return newH;

}


int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	nodeLink head = new node(1, 0);
	nodeLink p = head;
	for (int i = 2; i < N; ++i) {
		p = (p->next = new node(i, 0));
	}
	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	cout << "---------------------------" << endl;

	nodeLink newH = rearrange(head);
	for (p = newH; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


