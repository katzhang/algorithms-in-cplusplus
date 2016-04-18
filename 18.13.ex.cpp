/*
author: Kat Zhang
PROG: Implement a graph ADT client function that calls a client-supplied function for
each vertex in the graph.
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

	void eachVertex(void (*callback)(int)) {
		for (int i = 0; i < Vcnt; ++i) {
			callback(i);
		}
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

void print(int v) {
	cout << "v: " << v << endl;
}

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10);
	graph->insert(Edge(3, 7));
	graph->insert(Edge(1, 4));
	graph->insert(Edge(7, 8));

	graph->eachVertex(print);
}

