/*
author: Kat Zhang
PROG: Implement a class that provides clients with the capability to learn the indegree
and outdegree of any given vertex in a digraph, in constant time, after linear-time preprocessing
in the constructor. Then add member functions that return the number of sources and sinks, 
in constant time.
*/

#include <vector>
#include "17.9.graph-adt-imp-adj-list.cpp"

using namespace std;

template<class Graph> class DEGREE {
	const Graph& G;
	vector<int> inCount, outCount;
	int sourceCount, sinkCount;
public:
	DEGREE(const Graph& G): G(G), inCount(G.V(), 0), outCount(G.V(), 0) {
		for (int v = 0; v < G.V(); ++v) {
			cout << "v: " << v << endl;
			typename Graph::adjIterator A(G, v);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				cout << "  " << "t: " << t << endl;
				outCount[v]++;
				inCount[t]++;
			}
		};
		for (int v = 0; v < G.V(); ++v) {
			if (outCount[v] == 0) sinkCount++;
			if (inCount[v] == 0) sourceCount++;
		};
	}
	int getIndegree(int v) {
		return inCount[v];
	}
	int getOutdegree(int v) {
		return outCount[v];
	}
	int getSourceCount() {
		return sourceCount;
	}
	int getSinkCount() {
		return sinkCount;
	}
};


int main() {
	SparseMultiGRAPH* graph = new SparseMultiGRAPH(10, true);
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

	DEGREE<SparseMultiGRAPH>* d = new DEGREE<SparseMultiGRAPH>(*graph);
	cout << d->getOutdegree(9) << endl;
	cout << "sources: " << d->getSourceCount() << endl;
	cout << "sinks: " << d->getSinkCount() << endl;
}

