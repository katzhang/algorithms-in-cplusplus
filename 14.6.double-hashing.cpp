/*
author: Robert Sedgewick
PROG: Double hashing
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item* st;
	Item nullItem;
	int N, M;
public:
	ST(int maxN) {
		N = 0;
		M = 2 * maxN;
		st = new Item[M];
		for (int i = 0; i < M; ++i) {
			st[i] = nullItem;
		}
	}
	int count() const {
		return N;
	}
	inline int hashtwo(Key v) {
		return (v % 97) + 1;
	}
	void insert(Item item) {
		Key v = item.key();
		int i = hash(v, M), k = hashtwo(v, M);
		while (!st[i].null()) {
			i = (i + k) % M;
		}
		st[i] = item;
		N++;

	}
	Item search(Key v) {
		int i = hash(v, M), k = hashtwo(v, M);
		while (!st[i].null()) {
			if (v == st[i].key()) {
				return st[i];
			} else {
				i = (i + k) % M;
			}
		}
		return nullItem;
	}
};



