/*
author: Robert Sedgewick
PROG: Simple path search (depth first search)
*/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w) {};
};

class GRAPH {
private:
	// Implementation-dependent code
public:
	GRAPH(int, bool);
	~GRAPH();
	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);
	class adjIterator {
	public:
		adjIterator(const GRAPH, int);
		int beg();
		int nxt();
		bool end();
	};
};

template <class Graph> 
class sPATH {
	const Graph& G;
	vector<bool> visited;
	bool found;
	bool searchR(int v, int w) {
		if (v == w) return true;
		visited[v] = true;
		typename Graph::adjIterator A(G, v);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (!visited[t]) {
				if (searchR(t, w)) return true;
			}
		}
		return false;
	}
public:
	sPath(const Graph& G, int v, int w) : G(G), visited(G.V(), false) {
		found = searchR(v, w);
	}
	bool exists() const {
		return found;
	}
};













