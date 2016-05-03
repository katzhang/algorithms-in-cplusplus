/*
author: Robert Sedgewick
PROG: Improved BFS
*/

#include <iostream>
#include <vector>
#include "4.15.fifo-queue-array-implementation.cpp"

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

template<class Graph> class BFS: public SEARCH<Graph> {
	vector<int> parent;
	void searchC(Edge e) {
		QUEUE<Edge> Q;
		Q.put(e);
		ord[e.w] = cnt++;
		while (!Q.empty()) {
			e = Q.get();
			parent[e.w] = e.v;
			typename Graph::adjIterator A(G, e.w);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				if (ord[t] == -1) {
					Q.put(Edge(e.w, t));
					ord[t] = cnt++;
				}
			}
		}
	}
public:
	BFS(Graph &G) : SEARCH<Graph>(G), parent(G.V(), -1) {
		search();
	}
	int ST(int v) const {
		return parent[v];
	}
};








