/*
author: Kat Zhang
PROG: Use the STL to build a generalized-queue implementation for graph edges that disallows
edges with duplicates vertices on the queue, using an ignore-the-new-item policy
*/

#include <iostream>
#include <vector>
#include "4.15.fifo-queue-array-implementation.cpp"
#include "17.9.graph-adt-imp-adj-list.cpp"

using namespace std;

template<class Graph> class SEARCH {
	protected:
		const Graph& G;
		int cnt;
		vector<int> ord;
		virtual void searchC(Edge) = 0;
		virtual void findLength(Edge) = 0;
		void search() {
			for (int v = 0; v < G.V(); v++) {
				if (ord[v] == -1) searchC(Edge(v, v));
				findLength(Edge(v, v));
			}
		}
public:
	SEARCH(const Graph& G): G(G), ord(G.V(), -1), cnt(0) {};
	int operator[](int v) const {
		return ord[v];
	}
};

template<class Graph> class BFSSP: public SEARCH<Graph> {
	vector<int> st;
	vector<vector<int> > matrix;
	void searchC(Edge e) {
		QUEUE<Edge> Q(200);
		Q.put(e);
		this->ord[e.w] = this->cnt++;
		while (!Q.empty()) {
			e = Q.get();
			st[e.w] = e.v;
			typename Graph::adjIterator A(this->G, e.w);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				if (this->ord[t] == -1) {
					Q.put(Edge(e.w, t));
					this->ord[t] = this->cnt++;
				}
			}
		}
	}

public:
	BFSSP(Graph &G) : SEARCH<Graph>(G), st(G.V(), -1), matrix(G.V(), vector<int>(G.V(), 100)) {
		this->search();
	}
	int ST(int v) const {
		return st[v];
	}
	void printOrd() const {
		for (int i = 0; i < this->G.V(); ++i) {
			cout << i << "'s order: " << this->ord[i] << endl;
		}
	}
	void printSt() const {
		for (int i = 0; i < this->G.V(); ++i) {
			cout << i << "'s parent: " << st[i] << endl;
		}
	}

	int length(int v, int w) {
		return matrix[v][w];
	}
};

int main() {
	SparseMultiGRAPH* graph = new SparseMultiGRAPH(8);
	graph->insert(Edge(0, 2));
	graph->insert(Edge(0, 7));
	graph->insert(Edge(0, 5));
	graph->insert(Edge(1, 7));
	graph->insert(Edge(2, 6));
	graph->insert(Edge(6, 4));
	graph->insert(Edge(4, 7));
	graph->insert(Edge(4, 3));
	graph->insert(Edge(4, 5));
	graph->insert(Edge(3, 5));

	BFSSP<SparseMultiGRAPH>* bfs = new BFSSP<SparseMultiGRAPH>(*graph);

	cout << bfs->length(0, 7) << endl;
	cout << bfs->length(0, 1) << endl;
	cout << bfs->length(3, 6) << endl;
}







