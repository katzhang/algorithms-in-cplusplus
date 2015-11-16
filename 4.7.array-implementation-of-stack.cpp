/*
author: Robert Sedgewick
PROG: Array implementation of a pushdown stack
*/

#include <iostream>

template <class Item>
class STACK {
private:
	Item* s;
	int N;
public:
	STACK(int maxN) {
		s = new Item[maxN];
		N = 0;
	}
	int empty() {
		return N == 0;
	}
	void push(Item item) {
		s[N++] = item;
	}
	Item pop() {
		return s[--N];
	}
};