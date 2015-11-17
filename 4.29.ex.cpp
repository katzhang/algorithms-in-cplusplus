/*
author: Kat Zhang
PROG: Modify Program 4.11 to use path compression by halving
*/

#include <iostream>

using namespace std;

class UF{
private:
	int* id;
	int* sz;
	int find(int x) {
		while( x != id[x]) {
			id[x] = id[id[x]];
			x = id[x];
		}
		return x;
	}

public:
	UF(int N) {
		int id[N], sz[N];
		for (int i = 0; i < N; ++i) {
			id[i] = i;
			sz[i] = 1;
		}
	}
	int find(int p, int q) {
		return find(p) == find(q);
	}
	void unite(int p, int q) {
		int i = find(p), j = find(q);
		if (i == j) return;
		if (size[i] < size[j]) {
			id[i] = j;
			sz[j] += size[i];
		} else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}
}