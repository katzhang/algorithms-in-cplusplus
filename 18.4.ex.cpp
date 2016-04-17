/*
author: Kat Zhang
PROG: Add a public member function to Program 18.1 that returns the size 
of the connected component searched by the constructor.
*/

/*
Thought: size = number of edges. It also depends on if the graph is directed.
If the graph is directed, increment size as iterator iterates; if not,
to avoid double counting increment size only when encountering an unregistered node.
*/
#include <iostream>
#include <vector>

using namespace std;

template<class Graph> class cDFS {
	int count;
	int size;
	const Graph& G;
	vector<int> order;
	void searchC(int v) {
		order[v] = count++;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (G.directed()) size++;
			if (order[t] == -1) {
				searchC(t);
				if (!G.directed()) size++;
			}
		}
	}
public:
	cDFS(const Graph& G, int v = 0) : G(G), count(0), size(0), order(G.V(), -1) {
		searchC(v);
	}
	int count() const {
		return count;
	}
	int size() const {
		return size;
	}
	int operator[](int v) const {
		return order[v];
	}
};




