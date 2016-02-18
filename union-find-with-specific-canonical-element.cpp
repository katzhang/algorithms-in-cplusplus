/*
author: Kat Zhang
PROG: Union-find with specific canonical element

Add a method find() to the union-find data type so that find(i) returns the largest element 
in the connected component containing i.
The operations, union(), connected(), and find() should all take logarithmic time or better

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WeightedUnionFind {
private:
	int N;
	vector<int> id;
	vector<int> size;
	vector<vector<int> > groups;
public:
	WeightedUnionFind(int);
	bool connected(int, int);
	void unite(int, int);
	int find(int);
};

WeightedUnionFind::WeightedUnionFind(int n) {
	N = n;
	vector<int> self;
	for (int i = 0; i < N; ++i) {
		id.push_back(i);
		size.push_back(1);
		self.push_back(i);
		groups.push_back(self);
	}
}

bool WeightedUnionFind::connected(int p, int q) {
	int i, j;
	for (i = p; i != id[i]; i = id[i]);
	for (j = q; j != id[j]; j = id[j]);
	return (i == j) ? true : false;
}

void WeightedUnionFind::unite(int p, int q) {
	int i, j;
	for (i = p; i != id[i]; i = id[i]);
	for (j = q; j != id[j]; j = id[j]);
	if (size[i] < size[j]) {
		id[i] = j;
		size[j] += size[i];
		copy(groups[i].begin(), groups[i].end(), back_inserter(groups[j]));
	} else {
		id[j] = i;
		size[i] += size[j];
		copy(groups[j].begin(), groups[j].end(), back_inserter(groups[i]));
	}
}

int WeightedUnionFind::find(int i) {
	vector<int>::iterator max;
	for (; i != id[i]; i = id[i]);
	max = max_element(groups[i].begin(), groups[i].end());
	return *max;
}

int main() {

	WeightedUnionFind uf(10);

	uf.unite(0, 1);
	uf.unite(1, 2);
	uf.unite(2, 3);
	uf.unite(0, 8);

	cout << "max id connected with 0 is: " << uf.find(0) << endl;
}

