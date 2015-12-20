/*
author: Robert Sedgewick
PROG: Linked-list merge
*/

#include <iostream>
#include "6.15.linked-list-type-interface.h"

using namespace std;

nodeLink merge(link a, link b) {
	node dummy(0);
	nodeLink head = &dummy;
	nodeLink c = head;

	while((a != 0) && (b != 0)) {
		if (a->item < b->item) {
			c->next = a;
			c = a;
			a = a->next;
		} else {
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	c->next = (a == 0) ? b : a;
	return head->next;
}


int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]);
	char* a = new char[N];
	N = 0;
	while (cin >> a[N]) {
		N++;
	}
	merge(a, 0, 5, N - 1);
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}





