/*
author: Robert Sedgewick
PROG: A client function that prints a graph
*/

#include <iostream>
#include <vector>
#include "17.4.graph-processing-io-interface.cc"

using namespace std;

template <class Graph>
void IO<Graph>::show(const Graph& G) {
	for (int s = 0; s < G.V(); s++) {
		cout.width(2);
		cout << s << ": ";
		typename Graph::adjIterator A(G, s);
		for (int t = A.beg(); !A.end(); t = A.nxt()) {
			cout.width(2);
			cout << t << " ";
		}
		cout << endl;
	}
}