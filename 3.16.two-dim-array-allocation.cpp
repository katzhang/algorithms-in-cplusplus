/*
author: Robert Sedgewick
PROG: Two dimensional array allocation
*/

#include <iostream>
#include <string>

using namespace std;

int **malloc2d(int row, int col) {
	int **t = new int*[row];
	for (int i = 0; i < row; ++i) {
		t[i] = new int[col];
	}
	return t;
}

int main(int argc, char *argv[]) {
	int N = atoi(argv[1]), M = atoi(argv[2]);
	int **a = malloc2d(N, M);
}