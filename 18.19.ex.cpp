/*
author: Kat Zhang
PROG: Draw DFS forest that results from a standard adjacency-matrix DFS of the graph
*/

#include "17.7.graph-adt-imp-adj-matrix.cpp"

using namespace std;

template<class Graph> class SEARCH {
protected:
	const Graph& G;
	int cnt;
	int maxHeight;
	int height;
	int numberOfBackEdges;
	vector<int> ord;
	virtual void searchC(Edge) = 0;
	void search() {
		for (int v = 0; v < G.V(); v++) {
			if (ord[v] == -1) {
				height = 0;
				searchC(Edge(v, v));
				maxHeight = height > maxHeight ? height : maxHeight;
			}
		}
	}
public:
	SEARCH(const Graph& G): G(G), ord(G.V(), -1), cnt(0), maxHeight(0), numberOfBackEdges(0) {};
	int operator[](int v) const {
		return ord[v];
	}
};

template<class Graph> class DFS:public SEARCH<Graph> {
	vector<int> parent;
	void searchC(Edge e) {
		int w = e.w;
		this->ord[w] = this->cnt++;
		this->height++;
		parent[e.w] = e.v;
		typename Graph::adjIterator A(this->G, w);
		char* linkType;
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (this->ord[t] == -1) {
				searchC(Edge(w, t));
			} else {
				if (parent[w] != parent[t]) {
					this->numberOfBackEdges++;
				}
			}
		}
	}
public:
	DFS(const Graph& G): SEARCH<Graph>(G), parent(G.V(), -1) {
		this->search();
	}
	int PARENT(int v) const {
		return parent[v];
	}
	int getMaxHeight() const {
		return this->maxHeight;
	}
	int getNumberOfBackEdges() const {
		return this->numberOfBackEdges;
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10);
	// graph->insert(Edge(3, 7));
	// graph->insert(Edge(1, 4));
	// graph->insert(Edge(7, 8));
	// graph->insert(Edge(0, 5));
	// graph->insert(Edge(5, 2));
	// graph->insert(Edge(3, 8));
	// graph->insert(Edge(2, 9));
	// graph->insert(Edge(0, 6));
	// graph->insert(Edge(4, 9));
	// graph->insert(Edge(2, 6));
	// graph->insert(Edge(6, 4));

	graph->insert(Edge(0, 1));
	graph->insert(Edge(1, 2));
	graph->insert(Edge(2, 1));

	DFS<DenseGRAPH>* dfs = new DFS<DenseGRAPH>(*graph);
	cout << dfs->getMaxHeight() << endl;
	cout << dfs->getNumberOfBackEdges() << endl;
}

