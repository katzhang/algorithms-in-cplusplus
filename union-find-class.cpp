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
public:
	WeightedUnionFind(int);
	bool connected(int, int);
	void unite(int, int);
};

WeightedUnionFind::WeightedUnionFind(int n) {
	N = n;
	for (int i = 0; i < N; ++i) {
		id.push_back(i);
		size.push_back(1);
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
}

int main() {
	int N, timestamp, person_a, person_b, i, j;

	cout << "what is the total number of people?" << endl;
	cin >> N;

	WeightedUnionFind uf(N);

	cout << "enter logs: " << endl;

	while (cin >> timestamp >> person_a >> person_b) {

		// Weighted quick-union follows at most lgN poiters to determine if 2 are connected

		bool connected = uf.connected(person_a, person_b);

		cout << " person " << person_a << " and person " << person_b << " is connected: " << connected << endl;

		if (!connected) {
			uf.unite(person_a, person_b);
			cout << " person " << person_a << " and person " << person_b << " is connected now" << connected << endl;
		}
	}
}

