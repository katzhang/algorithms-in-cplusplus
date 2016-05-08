/*
author: Kat Zhang
PROG: Add a public memeber function to 18.7 that allows clients to test whether two vertices
are in the same edge-connected component.
*/

#include <iostream>
#include <vector>
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

template<class Graph> class EC : public SEARCH<Graph> {
	int bcnt;
	vector<int> low;
	void searchC(Edge e) {
		int w = e.w;
		this->ord[w] = this->cnt++;
		low[w] = this->ord[w];
		typename Graph::adjIterator A(this->G, w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (this->ord[t] == -1) {
				searchC(Edge(w, t));
				if (low[w] > low[t]) low[w] = low[t];
				if (low[t] == this->ord[t]) bcnt++; // w-t is a bridge
			} else if (t != e.v) {
				if (low[w] > this->ord[t]) {
					low[w] = this->ord[t];
				}
			}
		}
	}
public:
	EC(const Graph &G) : SEARCH<Graph>(G), bcnt(0), low(G.V() - 1) {
		this->search();
	}
	int count() const {
		return bcnt + 1;
	}
	bool isInEC(int v, int w) {
		return low[v] == low[w];
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10);
	graph->insert(Edge(3, 7));
	graph->insert(Edge(3, 8));
	graph->insert(Edge(7, 8));
	graph->insert(Edge(4, 7));

	EC<DenseGRAPH>* ec = new EC<DenseGRAPH>(*graph);

	cout << ec->isInEC(3, 7) << endl;
	cout << ec->isInEC(1, 7) << endl;
	cout << ec->isInEC(4, 7) << endl;
}








