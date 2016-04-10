/*
author: Kat Zhang
PROG: Stack with max. 
1. Determine whether a singly-linked data structure contains a cycle. 
2. If a singly-linked data structure contains a cycle, 
determine the first node that participates in the cycle. 
you may use only a constant number of pointers into the list 
(and no other variables). The running time of your algorithm should be 
linear in the number of nodes in the data structure.
*/

#include <iostream>
using namespace std;

struct node {
	int item;
	node* next;

	// Constructor
	node(int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node* nodeLink;

bool hasCycle(nodeLink first) {
	nodeLink slow, fast;
	slow = fast = first;

	while (slow->next != 0 && fast != 0 && fast->next != 0 && fast->next->next != 0) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

// Assume a cycle exists in the linked list
nodeLink getFirstNodeOfCycle(nodeLink first) {
	nodeLink slow, fast;
	slow = fast = first;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	
	while (true) {
		slow = slow->next;
		first = first->next;
		if (slow == first) break;
	}
	return slow;
}

int main() {
	nodeLink first, pointer, second;
	second = new node(2, 0);
	first = pointer = new node(1, 0);
	pointer->next = second;
	pointer = pointer->next;
	pointer->next = new node(3, 0);
	pointer = pointer->next;
	pointer->next = second;

	bool result = hasCycle(first);
	cout << "linked list has cycle? " << result << endl;
	nodeLink firstNodeOfCycle = getFirstNodeOfCycle(first);
	cout << "first node of cycle: " << firstNodeOfCycle->item << endl;

}



