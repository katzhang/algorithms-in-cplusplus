/*
author: Robert Sedgewick
PROG: Derived class for depth-first search
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

class DFS: public SEARCH<Graph> {
	vector<int> parent;
	void searchC(Edge e) {
		int w = e.w;
		ord[w] = cnt++;
		parent[e.w] = e.v;
		typename Graph::adjIterator A(G.w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (ord[t] == -1) searchC(Edge(w, t));
		}
	}
public:
	DFS(const Graph& G): SEARCH<Graph>(G), parent(G.V(), -1) {
		search();
	}
	int PARENT(int v) const {
		return parent[v];
	}

};

