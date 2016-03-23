/*
author: Robert Sedgewick
PROG: Graph ADT implementation (adjacency list)
*/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w) {};
};

class SparseMultiGRAPH {
	int Vcnt, Ecnt;
	bool digraph;
	struct node {
		int v;
		node* next;
		node(int x, node* t) {
			v = x;
			next = t;
		}
	};
	typedef node* nodeLink;
	vector<nodeLink> adj;
public:
	SparseMultiGRAPH(int V, bool digraph = false) : 
	adj(V), Vcnt(V), Ecnt(0), digraph(digraph) {
		adj.assign(V, 0);
	}
	int V() const { return Vcnt; }
	int E() const { return Ecnt; }
	bool directed() const { return digraph; }
	void insert(Edge e) {
		int v = e.v, w = e.w;
		adj[v] = new node(w, adj[v]);
		if (!digraph) adj[w] = new node(v, adj[w]);
		Ecnt++;
	}
	void remove(Edge e) {}
	bool edge(int v, int w) const {
		return adj[v][w];
	}
	class adjIterator;
	friend class adjIterator;
};

class SparseMultiGRAPH::adjIterator {
	const SparseMultiGRAPH& G;
	int v;
	nodeLink t;
public:
	adjIterator(const SparseMultiGRAPH& G, int v): G(G), v(v) {
		t = 0;
	}
	int beg() {
		t = G.adj[v];
		return t ? t->v : -1;
	}
	int nxt() {
		if (t) t = t->next;
		return t ? t->v : -1;
	}
	bool end() {
		return t == 0;
	}


};













