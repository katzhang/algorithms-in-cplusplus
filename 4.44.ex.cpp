/*
author: Kat Zhang
PROG: Provide an implementation for your deque interface (Exercise 4.43) 
that uses an array for the underlying data structure
*/

#include <iostream>

using namespace std;

template <class Item>
class DEQUE {
private:
	Item* deque;
	int N, head, tail;
public:
	DEQUE(int maxN) {
		deque = new Item[maxN + 1];
		N = maxN + 1;
		head = N / 2;
		tail = head;
	}
	int empty() const {
		return head % N == tail;
	}
	void addFirst(Item item) {
		deque[--head] = item;
	}
	void addLast(Item item) {
		deque[tail++] = item;
		tail = tail % N;
	}
	Item removeFirst() {
		Item headItem = deque[head];
		head++;
		return headItem;
	}
	Item removeLast() {
		Item tailItem = deque[tail];
		tail--;
		return tailItem;
	}
	void print() {
		while(head < tail) {
			cout << deque[head++] << " ";
		}
		cout << endl;
	}
};