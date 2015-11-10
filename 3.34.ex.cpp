/*
author: Kat Zhang
PROG:Write a function that moves the smallest item on a given list 
to be the first node on the list
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

nodeLink moveSmallestToFirst(nodeLink h) {
	int smallest = h->item;
	nodeLink p, newH;
	for (p = h; p != 0; p = p->next) {
		if (p->item < smallest) {
			smallest = p->item;
		}
	}

	newH = new node(smallest, h);
	
	for (p = newH; p != 0; p = p->next) {
		if ( p->next != 0 && p->next->item == smallest && p->next->next != 0) {
			p->next = p->next->next;
		}
	}

	return newH;

}


int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	nodeLink head = new node(rand() % 1000, 0);
	nodeLink p = head;
	for (int i = 1; i < N; ++i) {
		p = (p->next = new node(rand() % 1000, 0));
	}
	for (p = head; p != 0; p = p->next) {
		cout << p->item << endl;
	}

	cout << "---------------------------" << endl;

	nodeLink newH = moveSmallestToFirst(head);
	for (p = newH; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


