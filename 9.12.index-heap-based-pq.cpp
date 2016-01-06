/*
author: Robert Sedgewick
PROG: Index-heap-based priority queue
*/

#include <iostream>

using namespace std;

template <class Index>
class PQ {
private:
	int N;
	Index* pq;
	int* qp;
	void exch(Index i, Index j) {
		int t;
		t = qp[i];
		qp[i] = qp[j];
		qp[j] = t;
		pq[qp[i]] = i;
		pq[qp[j]] = j;
	}
	void fixUp(Index a[], int k) {
		while (k > 1 && a[k / 2] < a[k]) {
			exch(a[k], a[k / 2]);
			k = k / 2;
		}
	}
	void fixDown(Index a[], int k, int N) {
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
public:
	PQ(int maxN) {
		pq = new Index[maxN + 1];
		qp = new int[maxN + 1];
		N = 0;
	}
	int empty() const {
		N == 0;
	}
	void insert(Index v) {
		pq[++N] = v;
		qp[v] = N;
		fixUp(pq, N);
	}
	Index getmax() {
		exch(pq[1], pq[N]);
		fixDown(pq, 1, N - 1);
		return pq[N--];
	}
	void change(Index k) {
		fixUp(pq, qp[k]);
		fixDown(pq, qp[k], N);
	}
};



