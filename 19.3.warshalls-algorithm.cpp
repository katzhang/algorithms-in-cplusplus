/*
author: Robert Sedgewick
PROG: Warshall's Algorithm
*/

#include <iostream>
#include <vector>

using namespace std;

template <class tcGraph, Graph> class TC {
	tcGraph T;
public:
	TC(const Graph &G) : T(G) {
		for (int s = 0; s < T.V(); s++) {
			T.insert(Edge(s, s));
		}
		for (int i = 0; i < T.V(); i++) {
			for (int s = 0; s < T.V(); s++) {
				if (T.edge(s, i)) {
					for (int t = 0; t < T.V(); t++) {
						if (T.edge(i, t)) {
							T.insert(Edge(s, t));
						}
					}
				}
			}
		}
	}
	bool reachable(int s, int t) const {
		return T.edge(s, t);
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




