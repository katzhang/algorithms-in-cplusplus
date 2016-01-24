/*
author: Robert Sedgewick
PROG: Binary search (for array-based symbol table)
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item nullItem, *st;
	int N;
	Item searchR(int left, int right, Key v) {
		if (left > right) return nullItem;
		int m = (left + right) / 2;
		if (v == st[m].key()) return st[m];
		if (left == right) return nullItem;
		if (v < st[m].key()) {
			return searchR(left, m - 1, v);
		} else {
			return searchR(m + 1, right, v);
		}
	}
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
		return searchR(0, N - 1, v);
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
};

