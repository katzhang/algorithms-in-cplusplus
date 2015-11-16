/*
author: Kat Zhang
PROG: Modify the linked-list–based pushdown-stack implementation in the text (Program 4.8) 
to call a member function error() if the client attempts to pop when the stack is empty or 
if there is no memory available from new for a push
*/

#include <iostream>

using namespace std;

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
		// Question: how to test?
		try {
			head = new node(x, head);
		} catch(bad_alloc&) {
			error();
		}
	}
	Item pop() {
		Item result;
		if (empty()) {
			error();
			result = 0;
		} else {
			Item v = head->item;
			nodeLink second = head->next;
			delete head;
			head = second;
			result = v;
		}
		return result;

	}
	void error() {
		cout << "Error: the stack is " << (empty() ? "empty. " : "full. ") << endl;
	}
};

int main(int argc, char *argv[]) {
	int maxN = atoi(argv[1]);
	STACK<int> test(maxN);

	test.push(1);
	cout << test.pop() << endl;
	cout << test.pop() << endl;
}









