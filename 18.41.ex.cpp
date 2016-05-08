/*
author: Kat Zhang
PROG: Derive a class from 18.2 for determining whether a graph is biconnected, 
using a brute-force algorithm that runs in time proportional to V(V + E).
*/

#include <iostream>
#include <vector>
#include "17.7.graph-adt-imp-adj-matrix.cpp"

using namespace std;

template<class Graph> class SEARCH {
	protected:
		const Graph& G;
		vector<int> ord;
		bool isBiconnectedVal;
		virtual void searchC(Edge) = 0;
		void search() {
			for (int w = 0; w < G.V(); w++) {
				ord = vector<int>(G.V(), -1);
				ord[w] = 1; // Exclude vertex w
				for (int v = 0; v < G.V(); v++) {
					if (ord[v] == -1) {
						searchC(Edge(v, v));
						if (!isAllScanned()) {
							isBiconnectedVal = false;
						;
						}
					}
				}
			}
		}
		bool isAllScanned() {
			for (int o = 0; o < G.V(); ++o) {
				if (ord[o] == -1) {
					return false;
				}
			}
			return true;
		}
public:
	SEARCH(const Graph& G): G(G), isBiconnectedVal(true) {};
};

template<class Graph> class EC : public SEARCH<Graph> {
	void searchC(Edge e) {
		int w = e.w;
		this->ord[w] = 1;
		typename Graph::adjIterator A(this->G, w);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (this->ord[t] == -1) {
				searchC(Edge(w, t));
			}
		}
	}
public:
	EC(const Graph &G) : SEARCH<Graph>(G) {
		this->search();
	}
	bool isBiconnected() {
		return this->isBiconnectedVal;
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(3);
	graph->insert(Edge(1, 2));
	graph->insert(Edge(0, 1));
	graph->insert(Edge(0, 2));

	EC<DenseGRAPH>* ec = new EC<DenseGRAPH>(*graph);

	cout << ec->isBiconnected() << endl;
}








