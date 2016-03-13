/*
author: Robert Sedgewick
PROG: Graph-processing input/output interface
*/

#include <iostream>

using namespace std;

template <class Graph>
class IO {
public:
	static void show(const Graph&);
	static void scanEZ(Graph&);
	static void scan(Graph&);
}