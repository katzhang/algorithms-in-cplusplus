/*
author: Robert Sedgewick
PROG: Linked-list implementation of a first-class queue
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
	void deleteList() {
		for (nodeLink temp = head; temp != 0; head = temp) {
			temp = head->next;
			delete head;
		}
	}
public:
	QUEUE(int) {
		head = 0;
	}
	// Copy constructor
	QUEUE(const QUEUE& rhs) {
		head = 0;
		*this = rhs;
	}
	// Overloaded assignment operator
	QUEUE& operator=(const QUEUE& rhs) {
		if (this == &rhs) return *this;
		deleteList();
		nodeLink temp = rhs.head;
		while(temp != 0) {
			put(t->item);
			temp = temp->next;
		}
		return *this;
	}
	// Delete
	~QUEUE() {
		deleteList();
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