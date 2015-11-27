/*
author: Kat Zhang
PROG: Write a program that counts the number of nodes in a binary tree 
that have one external and one internal child
*/

#include <iostream>

using namespace std;

struct node {
	Item item;
	node* l, r;
	node(Item x) {
		item = x;
		l = 0;
		r = 0;
	};
};

typedef node* nodeLink;

bool isExternal(nodeLink n) {
	if (n != 0) {
		return (n->l == 0) && (n->r == 0);
	}
}

bool isInternal(nodeLink n) {
	return (n->l != 0) || (n->r != 0);
}

int count(nodeLink h) {
	if (h == 0) return 0;
	if (h->l != 0 && h->r != 0) {
		if ((isExternal(h->l) && isInternal(h->r)) || (isExternal(h->r) && isInternal(h->l))) {
			return count(h->l) + count(h->r) + 1;
		}
	}

	return count(h->l) + count(h->r);

}
