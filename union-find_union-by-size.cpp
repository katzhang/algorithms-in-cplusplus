/*
author: Kat Zhang
PROG: Union-by-size

Develop a union-find implementation that uses the same basic strategy as weighted quick-union 
but keeps track of tree height and always links the shorter tree to the taller one. 
Prove a lgN upper bound on the height of the trees for N sites with your algorithm.

*/

#include <iostream>

using namespace std;

static const int N = 100;

class WeightedUnionFind {
private:
	int id[N];
	int size[N];
	int height[N];
	int root(int i) {
		while (i != id[i]) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
public:
	WeightedUnionFind();
	bool connected(int, int);
	void uniteByHeight(int, int);
};

WeightedUnionFind::WeightedUnionFind() {
	for (int i = 0; i < N; ++i) {
		id[i] = i;
		size[i] = 1;
		height[i] = 1;
	}
}

bool WeightedUnionFind::connected(int p, int q) {
	return root(p) == root(q);
}

void WeightedUnionFind::uniteByHeight(int p, int q) {
	int root_p = root(p);
	int root_q = root(q);

	if (root_p == root_q) return;

	if (height[root_p] > height[root_q]) {
		id[root_q] = root_p;
	} else if (height[root_p] < height[root_q]) {
		id[root_p] = root_q;
	} else {
		id[root_q] = root_p;
		height[root_p]++;
	}
}


int main() {

	WeightedUnionFind uf;

	uf.uniteByHeight(0, 1);
	uf.uniteByHeight(1, 2);
	uf.uniteByHeight(2, 3);

	cout << "0 and 3 are connected: " << uf.connected(0, 3) << endl;
}

