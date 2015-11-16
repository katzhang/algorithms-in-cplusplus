/*
author: Kat Zhang
PROG: Suppose that you change the pushdown-stack interface to replace test 
if empty by count, which should return the number of items currently in the data structure. 
Provide implementations for count for the array representation (Program 4.7)
*/

#include <iostream>

using namespace std;

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
		return count() == 0;
	}
	int count() {
		return N;
	}
	void push(Item item) {
		s[N++] = item;
	}
	Item pop() {
		return s[--N];
	}
};