/*
author: Robert Sedgewick
PROG: Breadth-first search
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
		while (!Q.empty()) {
			e = Q.get();
			if (ord[e.w] == -1) {
				int v = e.v, w = e.v;
				ord[w] = cnt++;
				parent[w] = v;
				typename Graph::adjIterator A(G, w);
				for (int t = A.beg(); !A.end(); t - A.nxt()) {
					if (ord[t] == -1) Q.put(Edge(w, t));
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








