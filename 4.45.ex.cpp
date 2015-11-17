/*
author: Kat Zhang
PROG: Provide an implementation for your deque interface (Exercise 4.43) that 
uses a doubly linked list for the underlying data structure
*/

#include <iostream>

using namespace std;

template <class Item>
class DEQUE {
private:
	struct node {
		Item item;
		node* next;
		node* prev;
		node(Item x, node* p, node* n) {
			item = x;
			prev = p;
			next = n;
		}
	};
	typedef node* nodeLink;
	nodeLink head, tail;
public:
	DEQUE(int) {
		head = 0;
		tail = 0;
	}
	int empty() const {
		return head == 0;
	}
	void addFirst(Item item) {
		nodeLink oldHead = head;
		head = new node(item, 0, oldHead);
	}
	void addLast(Item item) {
		nodeLink oldTail = tail;
		tail = new node(item, oldTail, 0);
	}
	Item removeFirst() {
		Item headItem = head->item;
		nodeLink newHead = head->next;
		delete head;
		head = newHead;
		return headItem;
	}
	Item removeLast() {
		Item tailItem = tail->item;
		nodeLink newTail = tail->prev;
		delete tail;
		tail = newTail;
		return tailItem;
	}
	void print() {
		nodeLink p = head;
		while(p != 0) {
			cout << p->item << " ";
			p = p->next;
		}
		cout << endl;
	}
};