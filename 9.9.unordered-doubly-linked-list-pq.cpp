/*
author: Robert Sedgewick
PROG: Unordered doubly-linked-list priority queue
*/

#include <iostream>

using namespace std;

template <class Item>
class PQ {
private:
	struct node {
		Item item;
		node* prev;
		node* next;
		node(Item v) {
			item = v;
			prev = 0;
			next = 0;
		}
	};
	typedef node* nodeLink;
	nodeLink head, tail;
public:
	typedef node* handle;
	PQ(int = 0) {
		head = new node(0);
		tail = new node(0);
		head->prev = tail;
		head->next = tail;
		tail->prev = head;
		tail->next = head;

	}
	int empty() const {
		return head->next->next == head;
	}
	handle insert(Item v) {
		handle t = new node(v);
		t->next = head->next;
		t->next->prev = t;
		t->prev = head;
		head->next = t;
		return t;
	}
	Item getmax() {
		Item max;
		nodeLink x = head->next;
		for (nodeLink t = x; t->next != head; t = t->next) {
			if (x->item < t->item) x = t;
		}
		max = x->item;
		remove(x);
		return max;
	}
	void remove(handle x) {
		x->next->prev = x->prev;
		x->prev->next = x->next;
		delete x;
	}
	void change(handle x, Item v) {
		x->key = v;
	}
	void join(PQ<Item>& p) {
		tail->prev->next = p.head->next;
		p.head->next->prev = tail->prev;
		head->prev = p.tail;
		p.tail->next = head;
		delete tail;
		delete p.head;
		tail = p.tail;
	}
};



