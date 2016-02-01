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
	Item searchNR(int left, int right, Key v) {
		int m = (left + right) / 2;
		while (st[m].key() != v) {
			if (left >= right) return nullItem;
			if (v < st[m].key()) {
				right = m - 1;
			} else {
				left = m + 1;
			}
			m = (left + right) / 2;
		}
		return st[m];
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
		return searchNR(0, N - 1, v);
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

