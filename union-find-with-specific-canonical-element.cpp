/*
author: Kat Zhang
PROG: Union-find with specific canonical element

Add a method find() to the union-find data type so that find(i) returns the largest element 
in the connected component containing i.
The operations, union(), connected(), and find() should all take logarithmic time or better

*/

#include <iostream>
#include <vector>

using namespace std;

class WeightedUnionFind {
private:
	int N;
	vector<int> id;
	vector<int> size;
	vector<int> max;
public:
	WeightedUnionFind(int);
	bool connected(int, int);
	void unite(int, int);
	int find(int);
};

WeightedUnionFind::WeightedUnionFind(int n) {
	N = n;
	for (int i = 0; i < N; ++i) {
		id.push_back(i);
		size.push_back(1);
		max.push_back(i);
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
	} else {
		id[j] = i;
		size[i] += size[j];
	}

	if (max[i] > max[j]) {
		max[j] = max[i];
	} else {
		max[i] = max[j];
	}
}

int WeightedUnionFind::find(int i) {
	return max[i];
}

int main() {

	WeightedUnionFind uf(10);

	uf.unite(0, 1);
	uf.unite(1, 2);
	uf.unite(2, 3);
	uf.unite(0, 8);

	cout << "max id connected with 0 is: " << uf.find(0) << endl;
}

