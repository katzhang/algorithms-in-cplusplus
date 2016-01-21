/*
author: Robert Sedgewick
PROG: Linked-list-based symbol table (unordered)
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item nullItem;
	struct node {
		Item item;
		node* next;
		node(Item x, node* t) {
			item = x;
			next = t;
		}
	};
	typedef node* nodeLink;
	int N;
	nodeLink head;
	Item searchR(nodeLink t, Key v) {
		if (t == 0) return nullItem;
		if (t->item.key() == v) return t->item;
		return searchR(t->next, v);
	}
public:
	ST(int maxN) {
		head = 0;
		N = 0;
	}
	int count() {
		return N;
	}
	void insert(Item x) {
		head = new node(x, head);
		N++;
	}
	Item search(Key v) {
		return searchR(head, v);
	}
};

