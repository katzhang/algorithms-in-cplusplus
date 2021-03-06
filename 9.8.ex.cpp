/*
author: Kat Zhang
PROG: Provide an implementation for the basic priority queue interface that 
uses an unordered linked list for the underlying data structure.
*/

#include <iostream>

using namespace std;

template <class Item>
	class PQ {
	private:
		struct node {
			Item item;
			node* next;
			node(Item x) {
				item = x;
				next = 0;
			};
		};
		typedef node* nodeLink;
		nodeLink head, tail;
	public:
		PQ(int) {
			head = 0;
		}
		int empty() const {
			return head == 0;
		}
		void insert(Item item) {
			nodeLink oldTail = tail;
			tail = new node(item);
			if (head == 0) {
				head = tail;
			} else {
				oldTail->next = tail;
			}
		}
		Item getmax() {
			nodeLink p = head;
			Item max = head->item;
			while (p != 0) {
				if (p->item > max) max = p->item;
				p = p->next;
			}
			return max;
		}
	};

int main(int argc, char* argv[]) {
	int i, N = atoi(argv[1]), sw = atoi(argv[2]);
	int* a = new int[N];
	if (sw) {
		for (i = 0; i < N; ++i) {
			a[i] = 1000 * (1.0 * rand() / RAND_MAX);
		}
	} else {
		N = 0;
		while (cin >> a[N]) {
			N++;
		}
	}
	for (i = 0; i < N; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
	PQ<int> pq(50);
	for (i = 0; i < N; ++i) {
		pq.insert(a[i]);
	}
	cout << endl;
	cout << "get max: " << pq.getmax() << endl;
}




