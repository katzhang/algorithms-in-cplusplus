/*
author: Kat Zhang
PROG: Implement a digraph class that provides the capability for a client to check that
a digraph is indeed a DAG, and provide a DFS-based implementation
*/

#include <iostream>
#include <vector>

using namespace std;

template <class Graph> class DFS {
	const Graph &G;
	int depth, cnt, cntP;
	int backCnt;
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
				backCnt++;
			}
		}
		post[w] = cntP++;
		depth--;
	}
public:
	DFS(const Graph &G) : G(G), cnt(0), cntP(0), backCnt(0), pre(G.V(), -1), post(G.V(), -1) {
		for (int v = 0; v < G.V(); v++) {
			if (pre[v] == -1) {
				dfsR(Edge(v, v));
			}
		}
	}
	bool isDAG() {
		return backCnt == 0;
	}
};




