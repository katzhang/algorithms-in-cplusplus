/*
author: Kat Zhang
PROG: Write a recursive program that finds the maximum element in a linked list
*/

#include <iostream>

using namespace std;

struct node {
	int item;
	node* next;
	node(int x, node* t) {
		item = x;
		next = t;
	}
};
typedef node* nodeLink;

int findMax(nodeLink p, int max) {
	if (p->next == 0) return max > p->item ? max : p->item;
	max = max > p->item ? max : p->item;
	return findMax(p->next, max);
}

int main() {
	nodeLink h = new node(4, 0);
	nodeLink p = h;
	for (int i = 0; i < 6; ++i) {
		p->next = new node(i % 4, 0);
		p = p->next;
	}
	cout << "max: " << findMax(h, 0) << endl;
}