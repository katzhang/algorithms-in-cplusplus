/*
author: Kat Zhang
PROG: Because the exch primitive is used in the heapify operations, 
the items are loaded and stored twice as often as necessary. 
Give more efficient implementations that avoid this problem, a la insertion sort.
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
			pq[++N] = item;
			fixUp(pq, N);
		}
		Item getmax() {
			exch(pq[1], pq[N]);
			fixDown(pq, 1, N - 1);
			return pq[N--];
		}
	};

template <class Item>
	void fixUp(Item a[], int k) {
		int p = k;
		while (p > 1 && a[p / 2] < a[p]) {
			p = p / 2;
		}
		exch(a[p], a[k]);
	}

template <class Item>
	void fixDown(Item a[], int k, int N) {
		int oldK = k;
		while (2 * k <= N) {
			int j = 2 * k;
			if (j < N && a[j] < a[j + 1]) {
				j++;
			}
			if (!(a[k] < a[j])) {
				break;
			}
			k = j;
		}

		exch(a[k], a[oldK]);
	}



