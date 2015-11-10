/*
author: Kat Zhang
PROG: Write a function that takes two arguments—a link to a list 
and a function that takes a link as argument—
and removes all items on the given list for which the function returns a nonzero value
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

nodeLink filterList(nodeLink p, bool (*predicateFunction)(int)) {
	nodeLink copyP, newH = 0;
	while (p != 0) {
		if (predicateFunction(p->item)) {
			nodeLink newNode = new node(p->item, 0);
			if (newH == 0) {
				newH = newNode;
			}
			copyP = (copyP->next = newNode);
		}
		p = p->next;
	}
	return newH;
}

bool isEven(int n) {
	return n % 2 == 0;
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


	nodeLink newH = filterList(head, isEven);

	for (p = newH; p != 0; p = p->next) {
		cout << p->item << endl;
	}
}


