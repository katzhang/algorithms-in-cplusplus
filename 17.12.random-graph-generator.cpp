/*
author: Robert Sedgewick
PROG: Random graph generator (random edges)
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
	static void randE(Graph& G,  int E) {
		for (int i = 0; i < E; i++) {
			int v = int(G.V() * rand() / (1.0 + RAND_MAX));
			int w = int(G.V() * rand() / (1.0 + RAND_MAX));
			G.insert(Edge(v, w));
		}
	}
}