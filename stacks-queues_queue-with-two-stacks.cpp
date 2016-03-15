/*
author: Kat Zhang
PROG: Queue with two stacks. 
Implement a queue with two stacks so that each queue operations takes a constant 
amortized number of stack operations.
*/

#include <iostream>
using namespace std;

template <class Item>
class STACK {
private:
	Item* s;
	int N;
public:
	STACK() {
		s = new Item[50];
		N = 0;
	}
	int empty() {
		return N == 0;
	}
	int size() {
		return N;
	}
	void push(Item item) {
		s[N++] = item;
	}
	Item pop() {
		return s[--N];
	}
};

template <class Item>
class QUEUE {
private:
	int N, head, tail;
	STACK<Item> in;
	STACK<Item> out;

public:
	QUEUE(int maxN) {
		N = 0;
	}
	int empty() {
		return N == 0;
	}
	void put(Item x) {
		N++;
		in.push(x);
	}
	Item get() {
		if (N > 0) N--;
		if (out.empty()) {
			while (!in.empty()) {
				out.push(in.pop());
			}
		}
		return out.pop();
	}
};

int main() {
	QUEUE<int> q(10);
	q.put(4);
	q.put(3);
	cout << q.get() << endl;
	q.put(2);
	q.put(1);
	cout << q.get() << endl;
	cout << q.get() << endl;

}



