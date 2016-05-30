/*
author: Kat Zhang
PROG: Add a public function member to Program 19.3 to allow clients to use tc objects to
find the number of edges in the transitive closure.
*/

#include <iostream>
#include <vector>
#include "17.7.graph-adt-imp-adj-matrix.cpp"

using namespace std;

template <class tcGraph, class Graph> class TC {
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
	int edgeCount() {
		return T.E();
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10, true);
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

	TC<DenseGRAPH, DenseGRAPH>* tc = new TC<DenseGRAPH, DenseGRAPH>(*graph);
	cout << tc->reachable(7, 3) << endl;
	cout << tc->reachable(0, 9) << endl;
	cout << tc->edgeCount() << endl;
}




