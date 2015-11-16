/*
author: Kat Zhang
PROG: Extend Programs 4.5 and 4.6 to include 
the - (subtract) and / (divide) operations
*/

#include <iostream>
#include <string>
#include "4.7.array-implementation-of-stack.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	char* a = argv[1];
	int N = strlen(a);

	STACK<int> save(N);
	for (int i = 0; i < N; ++i) {
		if (a[i] == '+') {
			save.push(save.pop() + save.pop());
		}
		if (a[i] == '-') {
			save.push(- save.pop() + save.pop());
		}
		if (a[i] == '*') {
			save.push(save.pop() * save.pop());
		}
		if (a[i] == '/') {
			save.push(((float)1 / (float)save.pop()) * save.pop());
		}
		if ((a[i] >= '0') && (a[i] <= '9')) {
			save.push(0);
		}

		while ((a[i] >= '0') && (a[i] <= '9')) {
			save.push(10 * save.pop() + (a[i++] - '0'));
		}
	}

	cout << save.pop() << endl;
}