/*
author: Robert Sedgewick
PROG: Linked-list selection sort
*/

#include <iostream>
#include "6.15.linked-list-type-interface.h"

using namespace std;

nodeLink listselection(nodeLink h) {
	node dummy(0);
	nodeLink head = &dummy, out = 0;
	head->next = h;

	while(head->next != 0) {
		nodeLink max = findmax(head);
		nodeLink t = max->next;
		max->next = t->next;
		t->next = out;
		out = t;
	}
	return out;
}


