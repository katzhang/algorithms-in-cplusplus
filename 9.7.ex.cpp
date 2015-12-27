/*
author: Kat Zhang
PROG: Provide an implementation for the basic priority queue interface that 
uses an ordered array for the underlying data structure.
*/

#include <iostream>

using namespace std;

template <class Item>
	void exch(Item& A, Item& B) {
		Item t = A;
		A = B;
		B = t;
	}
template <class Item>
	void compexch(Item& A, Item& B) {
		if (B < A) {
			exch(A, B);
		}
	}

template <class Item>
	class PQ {
	private:
		Item* pq;
		int N;
	public:
		PQ(int maxN) {
			pq = new Item[maxN];
			N = 0;
		}
		int empty() const {
			return N == 0;
		}
		void insert(Item item) {
			pq[N++] = item;
			for (int i = 0; i < N; i++) {
				compexch(pq[i], pq[N - 1]);
			}
			for (int i = 0; i < N; i++) {
				cout << pq[i] << endl;
			}
		}
		Item getmax() {
			return pq[(N--) - 1];
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




