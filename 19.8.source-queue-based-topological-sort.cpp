/*
author: Robert Sedgewick
PROG: Source queue-based topological sort
*/

#include <iostream>
#include <vector>
#include "4.15.fifo-queue-array-implementation.cpp"

template <class Dag> class dagTS {
	const Dag &D;
	vector<int> in, ts, tsI;
public:
	dagTS(const Dag &D) : D(D), in(D.V(), 0), ts(D.V(), -1), tsI(D.V(), -1) {
		QUEUE<int> Q;
		for (int v = 0; v < D.V(); v++) {
			typename Dag::adjIterator A(D, v);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				in[t]++;
			}
		}
		for (int v = 0; v < D.V(); v++) {
			if (in[v] == 0) {
				Q.put(v);
			}
		}
		for (int j = 0; !Q.empty(); j++) {
			ts[j] = Q.get();
			tsI[ts[j]] = j;
			typename Dag::adjIterator A(D, ts[j]);
			for (int t = A.beg(); !A.end(); t = A.nxt()) {
				if (--in[t] == 0) {
					Q.put(t);
				}
			}
		}
	}
};




