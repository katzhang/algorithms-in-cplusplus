/*
author: Robert Sedgewick
PROG: Selection with a BST
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
	void insertR(nodeLink& h, Item x) {
		if (h == 0) {
			h = new node(x);
			return;
		}
		if (x.key() < h->item.key()) {
			insertR(h->left, x);
		} else {
			insertR(h->right, x);
		}
	}
	void insertT(nodeLink& h, Item x) {
		if (h == 0) {
			h = new node(x);
			return;
		}
		if (x.key() < h->item.key()) {
			insertT(h->left, x);
			rotR(h);
		} else {
			insertT(h->right, x);
			rotL(h);
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
	void partR(nodeLink& h, int k) {
		int t = (h->left == 0) ? 0 : h->left->N;
		if (t > k) {
			partR(h->left, k);
			rotR(h);
		}
		if (t < k) {
			partR(h->right, k - t - 1);
			rotL(h);
		}
	}
	// Assumes subtree size is maintained for each node
	Item selectR(nodeLink h, int k) {
		if (h == 0) return nullItem;
		int t = (h->left == 0) ? 0 : h->left->N;
		if (t > k) return selectR(h->left, k);
		if (t < k) return selectR(h->right, k - t - 1);
		return h->item;
	}
public:
	ST(int maxN) {
		head = 0;
	}
	Item search(Key v) {
		return searchR(head, v);
	}
	void insert(Item x) {
		insertT(head, x);
	}
	void show(ostream& os) {
		showR(head, os);
	}
	Item select(int k) {
		return selectR(head, k);
	}
};

