/*
author: Kat Zhang
PROG: Show, in the style of Figure 18.5, a trace of the recursive function calls 
made for a standard adjacency-matrix DFS of the graph
*/

#include "17.7.graph-adt-imp-adj-matrix.cpp"

using namespace std;

template<class Graph> class SEARCH {
protected:
	const Graph& G;
	int cnt;
	vector<int> ord;
	virtual void searchC(Edge) = 0;
	void search() {
		for (int v = 0; v < G.V(); v++) {
			if (ord[v] == -1) searchC(Edge(v, v));
		}
	}
public:
	SEARCH(const Graph& G): G(G), ord(G.V(), -1), cnt(0) {};
	int operator[](int v) const {
		return ord[v];
	}
};

template<class Graph> class DFS:public SEARCH<Graph> {
	vector<int> parent;
	void searchC(Edge e) {
		int w = e.w;
		cout << e.v << " - " << e.w << endl;
		this->ord[w] = this->cnt++;
		parent[e.w] = e.v;
		typename Graph::adjIterator A(this->G, w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (this->ord[t] == -1) searchC(Edge(w, t));
		}
	}
public:
	DFS(const Graph& G): SEARCH<Graph>(G), parent(G.V(), -1) {
		this->search();
	}
	int PARENT(int v) const {
		return parent[v];
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

