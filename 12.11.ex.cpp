/*
author: Kat Zhang
PROG: Modify the implementation of Program 12.4 to provide an eager implementation of count 
(by keeping track of the number of nonnull entries).
*/

#include <iostream>

using namespace std;

template<class Item, class Key>
class ST {
private:
	Item nullItem, *st;
	int M;
	int cnt;
public:
	ST(int maxN) {
		M = nullItem.key();
		st = new Item[M]; // Assume key value is always < M
		cnt = 0;
	}
	int count() {
		return cnt;
	}
	void insert(Item x) {
		st[x.key()] = x;
		cnt++;
	}
	Item search(Key v) {
		return st[v];
	}
	void remove(Item x) {
		st[x.key()] = nullItem;
	}
	Item select(int k) {
		for (int i = 0; i < M; i++) {
			if (!st[i].null()) {
				if (k-- == 0) return st[i];
			}
		}
		return nullItem;
	}
	void show(ostream& os) {
		for (int i = 0; i < M; i++) {
			if (!st[i].null()) {
				st[i].show(os);
			}
		}
	}
};

