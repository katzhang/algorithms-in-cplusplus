/*
author: Robert Sedgewick
PROG: Add an implementation for the remove operation to 
our ordered-array–based symbol-table implementation (Program 12.5).
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item nullItem, *st;
	int N;
public:
	ST(int maxN) {
		st = new Item[maxN + 1];
		N = 0;
	}
	int count() {
		return N;
	}
	void insert(Item x) {
		int i = N++;
		Key v = x.key();
		while (i > 0 && v < st[i - 1].key()) {
			st[i] = st[i - 1];
			i--;
		}
		st[i] = x;
	}
	Item search(Key v) {
		for (int i = 0; i < N; i++) {
			if (!(st[i].key() < v)) break;
		}
		if (v == st[i].key()) return st[i];
		return nullItem;
	}
	Item select(int k) {
		return st[k];
	}
	void show(ostream& os) {
		int i = 0;
		while (i < N) {
			st[i++].show(os);
		}
	}
	void remove(Item x) {
		Item& existingItem = search(x.key());
		existingItem = nullItem;
	}
};

