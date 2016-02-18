/*
author: Kat Zhang
PROG: Successor with delete

Given a set of N integers S={0,1,...,N−1} and a sequence of requests of the following form:
Remove x from S
Find the successor of x: the smallest y in S such that y≥x.
design a data type so that all operations (except construction) should take logarithmic time or better.

*/

#include <iostream>

using namespace std;

static const int N = 100;

class Sequence {
private:
	int id[N];
	int size[N];
	int suc[N];
	void unite(int p, int q) {
		int i, j;
		for (i = p; i != id[i]; i = id[i]);
		for (j = q; j != id[j]; j = id[j]);
		if (size[i] < size[j]) {
			id[i] = j;
			size[j] += size[i];
		} else {
			id[j] = i;
			size[i] += size[j];
		}

		if (suc[i] > suc[j]) {
			suc[j] = suc[i];
		} else {
			suc[i] = suc[j];
		}
	}

public:
	Sequence();
	void remove(int);
	int findSuccessor(int);
};

Sequence::Sequence() {
	for (int i = 0; i < N; ++i) {
		id[i] = i;
		size[i] = 1;
		suc[i] = i;
	}
}

void Sequence::remove(int i) {
	unite(i, i + 1);
}

int Sequence::findSuccessor(int i) {
	return suc[i];
}

int main() {

	Sequence sq;

	sq.remove(1);
	sq.remove(2);
	sq.remove(5);

	cout << "max id connected with 1 is: " << sq.findSuccessor(1) << endl;
}

