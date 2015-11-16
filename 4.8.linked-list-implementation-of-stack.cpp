/*
author: Robert Sedgewick
PROG: Linked-list implementation of a pushdown stack
*/

#include <iostream>

template <class Item>
class STACK {
private:
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
public:
	STACK(int) {
		head = 0;
	}
	int empty() {
		return head == 0;
	}
	void push(Item x) {
		head = new node(x, head);
	}
	Item pop() {
		Item v = head->item;
		nodeLink second = head->next;
		delete head;
		head = second;
		return v;
	}
}