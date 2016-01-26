/*
author: Robert Sedgewick
PROG: Sorting with a BST
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
	void showR(nodeLink h, ostream& os) {
		if (h == 0) return;
		showR(h->left, os);
		h->item.show(os);
		showR(h->right, os);
	}
public:
	ST(int maxN) {
		head = 0;
	}
	Item search(Key v) {
		return searchR(head, v);
	}
	void insert(Item x) {
		insertR(head, x);
	}
	void show(ostream& os) {
		showR(head, os);
	}
};

