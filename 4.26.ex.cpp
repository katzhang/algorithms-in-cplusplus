/*
author: Kat Zhang
PROG: Write a linked-list–based pushdown-stack implementation that keeps items on the list 
in order from least recently inserted to most recently inserted. 
You will need to use a doubly linked list
*/

#include <iostream>

using namespace std;

template <class Item>
class STACK {
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
	nodeLink tail;
public:
	STACK(int) {
		tail = 0;
	}
	int empty() {
		return tail == 0;
	}
	void push(Item x) {
		tail = new node(x, tail, 0);
	}
	Item pop() {
		Item v = tail->item;
		nodeLink nextTail = tail->prev;
		delete tail;
		tail = nextTail;
		return v;
	}
};

int main(int argc, char *argv[]) {
	int maxN = atoi(argv[1]);
	STACK<int> test(maxN);

	test.push(1);
	test.push(2);
	test.push(23);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
	cout << test.empty() << endl;
}









