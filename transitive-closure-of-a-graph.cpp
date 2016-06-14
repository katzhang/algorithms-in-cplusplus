/*
author: GeeksForGeeks
PROG: http://www.geeksforgeeks.org/transitive-closure-of-a-graph/
*/

#include <iostream>

using namespace std;

#define V 4

void printSolution(int reach[][V]);

void transitiveClosure(int graph[][V]) 
{
	int reach[V][V], i, j, k;

	// Initialize the solution matrix to be the same as input graph matrix
	for (i = 0; i < V; ++i) {
		for (j = 0; j < V; ++j) {
			reach[i][j] = graph[i][j];
		}
	}

	for (k = 0; k < V; ++k) {
		for (i = 0; i < V; ++i) {
			for (j = 0; j < V; ++j) {
				reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
			}
		}
	}

	printSolution(reach);
}

void printSolution(int reach[][V])
{
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			cout << reach[i][j];
		}
		cout << endl;
	}
}


int main() {
	int graph[V][V] = {
		{1, 1, 0, 1},
		{0, 1, 1, 0},
		{0, 0, 1, 1},
		{0, 0, 0, 1}
	};

	transitiveClosure(graph);
}




