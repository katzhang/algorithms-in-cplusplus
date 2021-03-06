/*
author: Robert Sedgewick
PROG: Graph connectivity
*/

#include <iostream>
#include <vector>
#include "18.4.graph-connectivity.cpp"

using namespace std;

template<class Graph> class EULER : public SEARCH<Graph> {
	void searchC(Edge e) {
		int v = e.v, w = e.w;
		ord[w] = cnt++;
		cout << "-" << w;
		typename Graph::adjIterator A(G, w);

		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (ord[t] == -1) {
				searchC(Edge(w, t));
			} else if (ord[t] < ord[v]) {
				cout << "-" << t << "-" << w;
			}
		}
		if (v != w) {
			cout << "-" << v;
		} else {
			cout << endl;
		}
	}
public:
	EULER(const Graph &G) : SEARCH<Graph>(G) {
		search();
	}
};

