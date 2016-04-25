/*
author: Robert Sedgewick
PROG: Edge Connectivity
*/

#include <iostream>
#include <vector>

using namespace std;

template<class Graph> class SEARCH {
	protected:
		const Graph& G;
		int cnt;
		vector<int> ord;
		virtual void searchC(Edge) = 0;
		void search() {
			for (int v = 0; v < G.V(); v++) {
				if (ord[v] == -1) searchC(Edge(v, v));
			}
		}
public:
	SEARCH(const Graph& G): G(G), ord(G.V(), -1), cnt(0) {};
	int operator[](int v) const {
		return ord[v];
	}
};

template<class Graph> class EC : public SEARCH<Graph> {
	int bcnt;
	vector<int> low;
	void searchC(Edge e) {
		int w = e.w;
		ord[w] = cnt++;
		low[w] = ord[w];
		typename Graph::adjIterator A(G, w);
		for (int t = A.beg(); !A.end(); t = nxt()) {
			if (ord[t] == -1) {
				searchC(Edge(w, t));
				if (low[w] > low[t]) low[w] = low[t];
				if (low[t] == ord[t]) bcnt++; // w-t is a bridge
			} else if (t != e.v) {
				if (low[w] > ord[t]) {
					low[w] = ord[t];
				}
			}
		}
	}
public:
	EC(const Graph &G) : SEARCH<Graph>(G), bcnt(0), low(G.V() - 1) {
		search();
	}
	int count() const {
		return bcnt + 1;
	}
};








