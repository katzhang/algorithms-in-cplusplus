/*
author: Kat Zhang
PROG: Implement a DFS-based cycle-testing class that preprocesses a graph in time proportional
to V in the constructor to support public member functions.
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
	bool hasCycle;
	void searchC(Edge e) {
		int w = e.w;
		cout << e.v << " - " << e.w << " ->tree link" << endl;
		this->ord[w] = this->cnt++;
		parent[e.w] = e.v;
		typename Graph::adjIterator A(this->G, w);
		char* linkType;
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			if (this->ord[t] == -1) {
				searchC(Edge(w, t));
			} else {
				// cout << "parent t: " << parent[t] << " w: " << w << endl;
				if (parent[t] == parent[w]) {
					linkType = "parent link";
					cout << w << " - " << t << " ->" << linkType << endl;
					return;
				}  else {
					if (!hasCycle) {
						hasCycle = true;
					}
				}
			}
		}
	}
public:
	DFS(const Graph& G): SEARCH<Graph>(G), parent(G.V(), -1), hasCycle(false) {
		this->search();
	}
	int PARENT(int v) const {
		return parent[v];
	}

	bool getHasCycle() const {
		return hasCycle;
	}
};

int main() {
	DenseGRAPH* graph = new DenseGRAPH(10);
	graph->insert(Edge(3, 7));
	graph->insert(Edge(3, 5));

	DFS<DenseGRAPH>* dfs = new DFS<DenseGRAPH>(*graph);

	cout << dfs->getHasCycle() << endl;
}

