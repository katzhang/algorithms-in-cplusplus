/*
author: Robert Sedgewick
PROG: FIFO queue linked-list implementation
*/

#include <iostream>

template <class Item>
class QUEUE {
private:
	struct node {
		Item item;
		node* next;
		node(Item x) {
			item = x;
			next = 0;
		};
		typedef node* nodeLink;
		nodeLink head, tail;
	};
public:
	QUEUE(int) {
		head = 0;
	}
	int empty() {
		return head == 0;
	}
	void put(Item x) {
		nodeLink oldTail = tail;
		tail = new node(x, 0);
		if (head == 0) {
			head = tail;
		} else {
			oldTail->next = tail;
		}
	}
	Item get() {
		Item headItem = head->item;
		nodeLink newHead = head->next;
		delete head;
		head = newHead;
		return headItem;
	}
}