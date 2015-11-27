/*
author: Kat Zhang
PROG: Write a program that counts the leaves in a binary tree
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

int countLeaves(nodeLink h) {
	if (h == 0) return 0;
	if (h->l == 0 && h->r == 0) {
		return 1;
	} else {
		return countLeaves(h->l) + countLeaves(h->r);
	}
}
