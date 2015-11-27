/*
author: Kat Zhang
PROG: Give a nonrecursive implementation of inorder traversal
Reference: http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
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

void pushLeftNodes(nodeLink n, STACK<nodeLink> s) {
	while(n != 0) {
		s.push(n);
		n = n->l;
	}
}

void traverse(nodeLink h, void visit(nodeLink)) {
	STACK<nodeLink> s(max);
	pushLeftNodes(h, s);
	while (!s.empty()) {
		visit(h = s.pop());
		h = h->r;
		pushLeftNodes(h, s);
	}
}