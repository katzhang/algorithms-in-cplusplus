/*
author: Robert Sedgewick
PROG: Bottom-up heapify
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

template <class Item>
	void exch(Item& A, Item& B) {
		Item t = A;
		A = B;
		B = t;
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
		}
		Item getmax() {
			int max = 0;
			for (int j = 1; j < N; j++) {
				if (pq[max] < pq[j]) max = j;
			}
			exch(pq[max], pq[N - 1]);
			return pq[--N];
		}
	};

template <class Item>
	void fixUp(Item a[], int k) {
		while (k < 1 && a[k / 2] < a[k]) {
			exch(a[k], a[k / 2]);
			k = k / 2;
		}
	}



