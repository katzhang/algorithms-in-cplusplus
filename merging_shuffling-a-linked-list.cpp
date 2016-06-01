/*
author: Kat Zhang
PROG: Shuffling a linked list
Given a singly-linked list containing N items, rearrange the items uniformly at random.
Your algorithm should consume a logarithmic (or constant) amount of extra memory and run in time proportional to
NlogN in the worst case.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;

	// Constructor
	node(int x, node* n = 0) {
		item = x;
		next = n;
	}

	void print() {
		node* p = next;
		cout << item;
		while (p != 0) {
			cout << ", " << p->item;
			p = p->next;
		}
		cout << endl;
	}
};

typedef node* nodeLink;

nodeLink merge(nodeLink leftHead, nodeLink rightHead) {
	nodeLink left = leftHead;
	nodeLink right = rightHead;

	if (rand() % 2 == 0) {
		leftHead = right;
		right = right->next;
	} else {
		left = left->next;
	}

	nodeLink iterator = leftHead;

	while (right != 0 || left != 0) {
		if (left == 0) {
			iterator->next = right;
			right = right->next;
		} else if (right == 0) {
			iterator->next = left;
			left = left->next;
		} else if (rand() % 2 == 0) {
			iterator->next = right;
			right = right->next;
		} else {
			iterator->next = left;
			left = left->next;
		}

		iterator = iterator->next;
	}
	return leftHead;
}

nodeLink shuffle(nodeLink head, int n) {
	if (n == 1) return head;
	int i = 1;
	nodeLink mid = head;
	while (i < n / 2) {
		mid = mid->next;
		i++;
	}
	nodeLink rightHead = mid->next;
	mid->next = 0;
	nodeLink newHead = shuffle(head, n / 2);
	nodeLink newRightHead = shuffle(rightHead, n - n / 2);
	nodeLink newResultHead = merge(newHead, newRightHead);
	return newResultHead;
}


int main() {
	srand (time(NULL));

	nodeLink a = new node(1, 0);
	a->next = new node(2, 0);
	a->next->next = new node(3, 0);
	a->next->next->next = new node(4, 0);

	nodeLink result = shuffle(a, 4);
	result->print();

}



