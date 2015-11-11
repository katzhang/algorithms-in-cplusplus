/*
author: Kat Zhang
PROG: Write a program to convert a sparse matrix from a two-dimensional array 
to a multilist with nodes for only nonzero values
*/

#include <iostream>

using namespace std;

struct node {
	int item;
	node* next;

	// Constructor
	node(int x, node* t) {
		item = x;
		next = t;
	}
};

typedef node* nodeLink;

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]);
	int mulArray[N][N];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			mulArray[i][j] = rand() % 2;
		}
	}

	nodeLink mulList[N];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << mulArray[i][j] << " ";

			if ( mulArray[i][j] != 0) {
				mulList[j] = new node(i, mulList[j]);
				mulList[i] = new node(j, mulList[i]);
			}
		}
		cout << endl;
	}
}


