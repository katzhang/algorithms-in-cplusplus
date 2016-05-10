/*
author: Kat Zhang
PROG: Draw the BFS forest that results from a standard adjacency-lists
BFS of the graph.
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

template<class Graph> class BFS: public SEARCH<Graph> {
	vector<int> st;
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
	BFS(Graph &G) : SEARCH<Graph>(G), st(G.V(), -1) {
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
};

int main() {
	SparseMultiGRAPH* graph = new SparseMultiGRAPH(10);
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

	BFS<SparseMultiGRAPH>* bfs = new BFS<SparseMultiGRAPH>(*graph);

	bfs->printOrd();
	bfs->printSt();
}





