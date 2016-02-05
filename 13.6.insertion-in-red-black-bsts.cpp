/*
author: Robert Sedgewick
PROG: Insertion in red–black BSTs
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	struct node {
		Item item;
		node* left, right;
		node(Item x) {
			item = x;
			left = 0;
			right = 0;
		}
	};
	typedef node* nodeLink;
	nodeLink head;
	Item nullItem;
	int red(nodeLink x) {
		if (x == 0) return 0;
		return x->red;
	}
	Item searchR(nodeLink h, Key v) {
		if (h == 0) return nullItem;
		Key t = h->item.key();
		if (v == t) return h->item;
		if (v < t) {
			return searchR(h->left, v);
		} else {
			return searchR(h->right, v);
		}
	}
	void showR(nodeLink h, ostream& os) {
		if (h == 0) return;
		showR(h->left, os);
		h->item.show(os);
		showR(h->right, os);
	}
	void rotR(nodeLink& h) {
		nodeLink x = h->left;
		h->left = x->right;
		x->right = h;
		h = x;
	}
	void rotL(nodeLink& h) {
		nodeLink x = h->right;
		h->right = x->left;
		x->left = h;
		h = x;
	}
	void RBinsert(nodeLink& h, Item x, int sw) {
		if (h == 0) {
			h = new node(x);
			return;
		}
		if (red(h->left) && red(h->right)) {
			h->red = 1;
			h->left->red = 0;
			h->right->red = 0;
		}
		if (x.key() < h->item.key()) {
			RBinsert(h->left, x, 0);
			if (red(h) && red(h->left) && sw) {
				rotR(h);
			}
			if (red(h->left) && red(h->left->left)) {
				rotR(h);
				h->red = 0;
				h->right->red = 1;
			}
		} else {
			RBinsert(h->right, x, 1);
			if (red(h) && red(h->right) && !sw) {
				rotL(h);
			}
			if (red(h->right) && red(h->right->right)) {
				rotL(h);
				h->red = 0;
				h->left->red = 1;
			}
		}
	}

public:
	ST(int maxN) {
		head = 0;
	}
	Item search(Key v) {
		return searchR(head, v);
	}
	void insert(Item x) {
		RBinsert(head, x, 0);
		head->red = 0;
	}
	void show(ostream& os) {
		showR(head, os);
	}
};

