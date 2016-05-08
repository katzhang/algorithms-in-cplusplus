/*
author: Robert Sedgewick
PROG: Generalized graph search
*/

#include <iostream>
#include <vector>
#include "18.11.random-queue-implementation.cpp"

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

template<class Graph> class PFS: public SEARCH<Graph> {
	vector<int> st;
	void searchC(Edge e) {
		GQ<Edge> Q(G.V());
		Q.put(e);
		ord[e.w] = cnt++;
		while (!Q.empty()) {
			e = Q.get();
			st[e.w] = e.v;
			typename Graph::adjIterator A(G, e.w);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				if (ord[t] == -1) {
					Q.put(Edge(e.w, t));
					ord[t] = cnt++;
				} else if (st[t] == -1) {
					Q.update(Edge(e.w, t));
				}
			}
		}
	}
public:
	PFS(Graph &G) : SEARCH<Graph>(G), st(G.V(), -1) {
		search();
	}
	int ST(int v) const {
		return st[v];
	}
};








