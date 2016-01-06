/*
author: Robert Sedgewick
PROG: Priority queue ADT interface for index items
*/

#include <iostream>

using namespace std;

template <class Index>
class PQ {
private:
	// Implementation-dependent code
public:
	PQ(int);
	int empty() const;
	void insert(Index);
	Index getmax();
	void change(Index);
	void remove(Index);
};



