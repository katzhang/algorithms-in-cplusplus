/*
author: Robert Sedgewick
PROG: Linked-list–type interface definition
*/

#include <iostream>

using namespace std;

struct node {
	Item item;
	node* next;
	node(Item x) {
		item = x;
		next = 0;
	}
};

typedef node* nodeLink;

nodeLink randlist(int);
nodeLink scanlist(int&);
void showlist(nodeLink);
nodeLink sortlist(nodeLink);


