/*
author: Kat Zhang
PROG: Give a BFS implementation that uses a queue of vertices.
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
		virtual void searchC(int) = 0;
		void search() {
			for (int v = 0; v < G.V(); v++) {
				if (ord[v] == -1) searchC(v);
			}
		}
public:
	SEARCH(const Graph& G): G(G), ord(G.V(), -1), cnt(0) {};
	int operator[](int v) const {
		return ord[v];
	}
};

template<class Graph> class BFS: public SEARCH<Graph> {
	void searchC(int v) {
		QUEUE<int> Q(200);
		Q.put(v); 
		this->ord[v] = this->cnt++;
		while (!Q.empty()) {
			v = Q.get();
			typename Graph::adjIterator A(this->G, v);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				if (this->ord[t] == -1) {
					Q.put(t);
					this->ord[t] = this->cnt++;
				}
			}
      }
  }
public:
	BFS(Graph &G) : SEARCH<Graph>(G) {
		this->search();
	}
	void printOrd() const {
		for (int i = 0; i < this->G.V(); ++i) {
			cout << i << "'s order: " << this->ord[i] << endl;
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
}





