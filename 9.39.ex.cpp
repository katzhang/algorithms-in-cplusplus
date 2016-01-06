/*
author: Kat Zhang
PROG: rovide implementations similar to Programs 9.9 and 9.10 that use ordered doubly linked lists. 
Note: Because the client has handles into the data structure, your programs can change only links 
(rather than keys) in nodes.
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
		nodeLink x = head->next;
		for (nodeLink t = x; t->next != head; t = t->next) {
			if (x->item >= t->item) {
				x->prev->next = t;
				t->prev = x->prev;
				t->next = x;
				x->prev = t;
				break;
			}
		}
		return t;
	}
	Item getmax() {
		Item max = tail->prev->item;
		remove(tail->prev);
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
		nodeLink p1 = head->next;
		nodeLink p2 = p.head->next;
		nodeLink p = head;
		while (p1 != head && p2 != p.head) {
			if (p1 < p2) {
				p->next = p1;
				p1 = p1->next;
			} else {
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		if (p1 == head) {
			while (p2 != p.head) {
				p->next = p2;
				p2 = p2->next;
				p = p->next;
			}
		}
		if (p2 == head) {
			while (p1 != p.head) {
				p->next = p1;
				p1 = p1->next;
				p = p->next;
			}
		}
		p->next = tail;
		delete p.tail;
		delete p.head;
	}
};



