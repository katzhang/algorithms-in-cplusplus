/*
author: Robert Sedgewick
PROG: Top-down heapify
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
	void fixDown(Item a[], int k, int N) {
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && a[j] < a[j + 1]) {
				j++;
			}
			if (!(a[k] < a[j])) {
				break;
			}
			exch(a[k], a[j]);
			k = j;
		}
	}



