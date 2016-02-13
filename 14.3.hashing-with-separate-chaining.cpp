/*
author: Robert Sedgewick
PROG: Hashing with separate chaining
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
	nodeLink head;
	Item searchR(nodeLink t, Key v) {
		if (t == 0) return nullItem;
		if (t->item.key() == v) return t->item;
		return searchR(t->next, v);
	}
	nodeLink* heads;
	int N, M;
public:
	ST(int maxN) {
		N = 0;
		M = maxN / 5;
		heads = new nodeLink[M];
		for (int i = 0; i < M; ++i) {
			heads[i] = 0;
		}
	}
	int count() {
		return N;
	}
	void insert(Item x) {
		int i = hash(item.key(), M);
		heads[i] = new node(item, heads[i]);
		N++;
	}
	Item search(Key v) {
		return searchR(heads[hash(v, M)], v);
	}
};



