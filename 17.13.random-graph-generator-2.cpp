/*
author: Robert Sedgewick
PROG: Random graph generator (random graph)
*/

#include <iostream>

using namespace std;

struct Edge {
	int v, w;
	Edge(int v = -1, int w = -1): v(v), w(w) {};
};

class GRAPH {
private:
	// Implementation-dependent code
public:
	GRAPH(int, bool);
	~GRAPH();
	int V() const;
	int E() const;
	bool directed() const;
	int insert(Edge);
	int remove(Edge);
	bool edge(int, int);
	class adjIterator {
	public:
		adjIterator(const GRAPH, int);
		int beg();
		int nxt();
		bool end();
	};
};

int main() {
	static void randG(Graph& G,  int E) {
		double p = 2.0 * E / G.V() / (G.V() - 1);
		for (int i = 0; i < G.V(); i++) {
			for (int j = 0; j < i; j++) {
				if (rand() < p * RAND_MAX) {
					G.insert(Edge(i, j));
				}
			}
		}
	}
}