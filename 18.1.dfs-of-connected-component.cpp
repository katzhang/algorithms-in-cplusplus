/*
author: Robert Sedgewick
PROG: Depth-first search of a connected component
*/

#include <iostream>
#include <vector>

using namespace std;

template<class Graph> class cDFS {
	int count;
	const Graph& G;
	vector<int> order;
	void searchC(int v) {
		order[v] = count++;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (order[t] == -1) searchC(t);
		}
	}
public:
	cDFS(const Graph& G, int v = 0) : G(G), count(0), order(G.V(), -1) {
		searchC(v);
	}
	int count() const {
		return count;
	}
	int operator[](int v) const {
		return order[v];
	}
};




