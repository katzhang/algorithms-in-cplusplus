/*
author: Kat Zhang
PROG: Modify the array-based pushdown-stack implementation in the text (Program 4.7) 
to call a member function error() if the client attempts to pop 
when the stack is empty or to push when the stack is full
*/

#include <iostream>

using namespace std;

template <class Item>
class STACK {
private:
	Item* s;
	int N, maxN;
public:
	STACK(int m) {
		maxN = m;
		s = new Item[maxN];
		N = 0;
	}
	int empty() {
		return N == 0;
	}
	void push(Item item) {
		if (N == maxN) {
			error();
		} else {
			s[N++] = item;
		}
	}
	Item pop() {
		if (N == 0) {
			error();
			return s[0];
		} else {
			return s[--N];
		}
	}
	void error() {
		cout << "Error: the stack is " << (N == 0 ? "empty. " : "full. ") << endl;
	}
};

int main(int argc, char *argv[]) {
	int maxN = atoi(argv[1]);
	STACK<int> test(maxN);

	test.push(1);
	test.push(2);
	test.pop();
	test.pop();
}









