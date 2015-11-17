/*
author: Kat Zhang
PROG: Modify the array-based FIFO queue implementation in the text (Program 4.15) to 
call a function error() if the client attempts to get when the queue is empty or 
to put when the queue is full
*/

#include <iostream>

template <class Item>
class QUEUE {
private:
	Item* q;
	int N, head, tail;
public:
	QUEUE(int maxN) {
		q = new Item[maxN + 1];
		N = maxN + 1;
		head = N;
		tail = 0;
	}
	int empty() const {
		return head % N == tail;
	}
	void put(Item item) {
		if (tail == N) {
			error();
		} else {
			q[tail++] = item;
			tail = tail % N;
		}
	}
	Item get() {
		if (empty()) {
			error(true);
		} else {
			head = head % N;
			return q[head++];
		}
	}
	void error(bool isEmpty) {
		cout << "Error: queue is ";
		if (isEmpty) {
			cout << "empty. ";
		} else {
			cout << "full. ";
		}
		cout << endl;
	}
}