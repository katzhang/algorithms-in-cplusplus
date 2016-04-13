/*
author: Robert Sedgewick
PROG: Euler path existence (linear time)
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
class ePATH {
	Graph G;
	int v, w;
	bool found;
	STACK<int> S;
	int tour(int v);
public:
	ePATH(const Graph& G, int v, int w) : G(G), v(v), w(w) {
		DEGREE<Graph> deg(G);
		int t = deg[v] + deg[w];
		if ((t % 2) != 0) {
			found = false;
			return;
		}
		for (t = 0; t < G.V(); t++) {
			if ((t != v) && (t != w)) {
				if ((deg[t] % 2) != 0) {
					found = false;
					return;
				}
			}
		}
		found = true;
	}
	bool exists() const {
		return found;
	}
	void show();
};

int ePATH<Graph>::tour(int v) {
	while (true) {
		typename Graph::adjIterator A(G, v);
		int w = A.beg();
		if (A.end()) break;
		S.push(v);
		G.remove(Edge(v, w));
		v = w;
	}
	return v;
}

void ePath<Graph>::show() {
	if (!found) return;
	while (tour(v) == v && !S.empty()) {
		v = S.pop();
		count << "-" << v;
	}
	cout << endl;
}













