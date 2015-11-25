/*
author: Robert Sedgewick
PROG: Construction of a parse tree
*/

#include <iostream>

using namespace std;

char* a;
int i;

struct node {
	Item item;
	node* l;
	node* r;
	node(Item x) {
		item = x;
		l = 0;
		r = 0;
	};
};

typedef node* nodeLink;

nodeLink parse() {
	char t = a[i++];
	nodeLink x = new nodeLink(t);
	if ((t == '+') || (t == '*')) {
		x->l = parse();
		x->r = parse();
	}
	return x;
}


