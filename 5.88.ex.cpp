/*
author: Kat Zhang
PROG: Write a recursive program that computes the internal path length of a binary tree
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

int countInternalPathLength(nodeLink h, int level) {
	if (h == 0) return level;
	if (h->l != 0 && h->r != 0) {
		return level + 1;
	} else {
		return countInternalPathLength(h->l) + countInternalPathLength(h->r);
	}
}
