/*
author: Kat Zhang
PROG: Clone a linked structure with two pointers per node.
Suppose that you are given a reference to the first node of a linked structure 
where each node has two pointers: one pointer to the next node in the sequence 
(as in a standard singly-linked list) and one pointer to an arbitrary node.
Design a linear-time algorithm to create a copy of the doubly-linked structure. 
You may modify the original linked structure, but you must end up with two copies of the original.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;
	node* random;

	// Constructor
	node(int x, node* n = 0, node* r = 0) {
		item = x;
		next = n;
		random = r;
	}
};

typedef node* nodeLink;

nodeLink cloneNode(nodeLink n) {
	nodeLink clonedNode = new node(n->item, n->next);
	n->next = clonedNode;
	return clonedNode;
}

nodeLink cloneList(nodeLink first) {
	nodeLink pointer = first;
	nodeLink clonePointer;
	nodeLink cloneFirst = 0;
	// First pass: copy the original node
	// make its next point to its clone, and its clone to the next node
	while (pointer) {
		if (cloneFirst == 0) {
			cloneFirst = cloneNode(pointer);
			clonePointer = cloneFirst;
		} else {
			clonePointer = cloneNode(pointer);
		}
		pointer = pointer->next;
	}

	// Reset pointers
	pointer = first;
	clonePointer = cloneFirst;

	// Second pass: set random node to clones and split the two lists
	while(pointer) {
		clonePointer->random = pointer->random->next;
		pointer->next = clonePointer->next; // Put the real next node back
		clonePointer->next = clonePointer->next->next;

		pointer = pointer->next;
		clonePointer = clonePointer->next;
	}
}


int main() {

}



