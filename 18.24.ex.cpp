/*
author: Kat Zhang
PROG: Implement the graph-connectivity class of 18.4 as a derived graph-search class.
*/
#include <iostream>
#include <vector>
#include "17.7.graph-adt-imp-adj-matrix.cpp"

using namespace std;

template<class Graph> class SEARCH {
protected:
	const Graph& G;
	int ccnt;
	vector<int> id;
	virtual void ccR(int) = 0;
	void search() {
		for (int v = 0; v < G.V(); v++) {
			if (id[v] == -1) {
				ccR(v);
				ccnt++;
			}
		}
	}
public:
	SEARCH(const Graph& G): G(G), id(G.V(), -1), ccnt(0) {};
	int count() const {
		return ccnt;
	}
	bool connect(int s, int t) const {
		return id[s] == id[t];
	}
};

template<class Graph> class DFS:public SEARCH<Graph> {
	vector<int> parent;
	void ccR(int w) {
		this->id[w] = this->ccnt;
		typename Graph::adjIterator A(this->G, w);
		for (int v = A.beg(); !A.end(); v = A.nxt()) {
			if (this->id[v] == -1) ccR(v);
		}
	}
public:
	DFS(const Graph& G): SEARCH<Graph>(G) {
		this->search();
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10);
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

	DFS<DenseGRAPH>* dfs = new DFS<DenseGRAPH>(*graph);
}

