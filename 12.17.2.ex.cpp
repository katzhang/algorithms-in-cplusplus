/*
author: Kat Zhang
PROG: Implement searchinsert functions for our list-based (Program 12.6) and array-based 
(Program 12.5) symbol-table implementations. They should search the symbol table for items 
with the same key as a given item, then insert the item if there is none.
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
	void searchinsert(Item x) {
		Item result = searchR(x.key());
		if (result == nullItem) {
			insert(x);
		}
	}
};

