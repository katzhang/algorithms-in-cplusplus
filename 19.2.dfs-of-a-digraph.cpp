/*
author: Robert Sedgewick
PROG: DFS of a digraph
*/

#include <iostream>
#include <vector>
#include "17.9.graph-adt-imp-adj-list.cpp"

using namespace std;

template <class Graph> class DFS {
	const Graph &G;
	int depth, cnt, cntP;
	vector<int> pre, post;
	void show(char *s, Edge e) {
		for (int i = 0; i < depth; i++) {
			cout << " ";
		}
		cout << e.v << "-" << e.w << s << endl;
	}
	void dfsR(Edge e) {
		int w = e.w;
		show(" tree", e);
		pre[w] = cnt++;
		depth++;
		typename Graph::adjIterator A(G, w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			Edge x(w, t);
			if (pre[t] == -1) {
				dfsR(x);
			} else if (post[t] == -1) {
				show(" back", x);
			} else if (pre[t] > pre[w]) {
				show(" down", x);
			} else {
				show(" cross", x);
			}
		}
		post[w] = cntP++;
		depth--;
	}
public:
	DFS(const Graph &G) : G(G), cnt(0), cntP(0), pre(G.V(), -1), post(G.V(), -1) {
		for (int v = 0; v < G.V(); v++) {
			if (pre[v] == -1) {
				dfsR(Edge(v, v));
			}
		}
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




