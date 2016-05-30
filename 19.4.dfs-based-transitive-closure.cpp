/*
author: Robert Sedgewick
PROG: DFS-based transitive closure
*/

#include <iostream>
#include <vector>

using namespace std;

template <class Graph> class tc {
	Graph T;
	const Graph &G;
	void tcR(int v, int w) {
		T.insert(Edge(v, w));
		typename Graph::adjIterator A(G, w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (!T.edge(v, t)) tcR(v, t);
		}
	}
public:
	tc(const Graph &G) : G(G), T(G.V(), true) {
		for (int v = 0; v < G.V(); v++) {
			tcR(v, v);
		}
	}
	bool reachable(int v, int w) {
		return T.edge(v, w);
	}
};

int main() {
	SparseMultiGRAPH* graph = new SparseMultiGRAPH(10, true);
	graph->insert(Edge(3, 7));
	graph->insert(Edge(1, 4));
	graph->insert(Edge(7, 8));
	graph->insert(Edge(0, 5));
	graph->insert(Edge(5, 2));
	graph->insert(Edge(3, 8));
	graph->insert(Edge(2, 9));
	graph->insert(Edge(0, 6));
	graph->insert(Edge(4, 9));
	graph->insert(Edge(2, 6));
	graph->insert(Edge(6, 4));

	DFS<SparseMultiGRAPH>* dfs = new DFS<SparseMultiGRAPH>(*graph);
}




