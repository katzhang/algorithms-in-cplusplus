/*
author: Kat Zhang
PROG: Modify the adjacency-matrix graph ADT implementation to use a dummy vertex that is connected
to all the other vertices. Then, provide a simplied DFS implementation that takes advantage of this change.

*/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w) {};
};

class DenseGRAPH {
	int Vcnt, Ecnt;
	bool digraph;
	vector <vector <bool> > adj;
	vector<int> heads;
public:
	DenseGRAPH(int V, bool digraph = false):
	adj(V), Vcnt(V), Ecnt(0), digraph(digraph), heads(V) {
		for (int i = 0; i < V; ++i) {
			adj[i].assign(V, false);
			heads.push_back(i);
		}
	}
	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	vector<int> connectedHeads() const { return heads; }
	bool directed() const { return digraph; }
	void insert(Edge e) {
		int v = e.v, w = e.w;
		if (adj[v][w] == false) Ecnt++;
		heads.erase(heads.begin() + w);
		adj[v][w] = true;
		if (!digraph) adj[w][v] = true;
	}
	void remove(Edge e) {
		int v = e.v, w = e.w;
		if (adj[v][w] == true) Ecnt--;
		adj[v][w] = false;
		if (!digraph) adj[w][v] = false;
	}
	bool edge(int v, int w) const {
		return adj[v][w];
	}

	class adjIterator;
	friend class adjIterator;
};

class DenseGRAPH::adjIterator {
	const DenseGRAPH& G;
	int i, v;
public:
	adjIterator(const DenseGRAPH& G, int v):
	G(G), v(v), i(-1) {};
	int beg() {
		i = -1;
		return nxt();
	}
	int nxt() {
		for (i++; i < G.V(); i++) {
			if (G.adj[v][i] == true) return i;
		}
		return -1;
	}
	bool end() {
		return i >= G.V();
	}
};


template<class Graph> class SEARCH {
protected:
	const Graph& G;
	int cnt;
	vector<int> ord;
	virtual void searchC(Edge) = 0;
	void search() {
		// for (int v = 0; v < G.V(); v++) {
		// 	if (ord[v] == -1) searchC(Edge(v, v));
		// }
		vector<int> heads = G.connectedHeads();
		vector<int>::size_type i = 0;
		int current;
		for(; i != heads.size(); ++i) {
			current = heads[i];
			if (ord[current] == -1) searchC(Edge(current, current));
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

