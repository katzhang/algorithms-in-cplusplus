/*
author: Robert Sedgewick
PROG: Connectivity interface
*/

#include <iostream>

using namespace std;

template <class Graph>
class CC {
private:
	// Implementation-dependent code
public:
	CC(const Graph&);
	int count();
	bool connect(int, int);
}