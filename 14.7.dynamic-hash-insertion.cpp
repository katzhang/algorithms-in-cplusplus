/*
author: Robert Sedgewick
PROG: Dynamic hash insertion (for linear probing)
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item* st;
	Item nullItem;
	int N, M;
	void expand() {
		Item* t = st;
		init(M + M);
		for (int i = 0; i < M/2; ++i) {
			if (!t[i].null()) {
				insert(t[i]);
			}
		}
		delete t;
	}
	void init(int maxN) {
		N = 0;
		M = 2 * maxN;
		st = new Item[M];
		for (int i = 0; i < M; ++i) {
			st[i] = nullItem;
		}
	}
public:
	ST(int maxN) {
		init(4);
	}
	int count() const {
		return N;
	}
	void insert(Item item) {
		int i = hash(item.key(), M);
		while (!st[i].null()) {
			i = (i + 1) % M;
		}
		st[i] = item;
		if (N++ >= M/2) expand();
	}
	Item search(Key v) {
		int i = hash(v, M);
		while (!st[i].null()) {
			if (v == st[i].key()) {
				return st[i];
			} else {
				i = (i + 1) % M;
			}
		}
		return nullItem;
	}
};



