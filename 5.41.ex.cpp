/*
author: Kat Zhang
PROG: Write a function that uses top-down dynamic programming to solve Exercise 5.40
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

int computeP(int i) {
	static int knowns[maxN];
	if (knowns[i] != 0) return knowns[i];
	int t = i;
	if (i < 1) return 0;
	bool isEven = (i % 2 == 0);
	if (i > 1) t = i / 2 + computeP(i / 2) + computeP(isEven ? (i / 2) : (i / 2 + 1));
	return knowns[i] = t;
}

int main() {
	int n;
	cin >> n;
	cout << "result: " << computeP(n) << endl;
}