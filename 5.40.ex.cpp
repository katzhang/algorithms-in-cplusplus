/*
author: Kat Zhang
PROG: Write a function that uses bottom-up dynamic programming to compute the value of 
PN defined by the recurrence
PN = floor(N/2) + P(floor(N/2)) + P(ceiling(N/2))
*/

#include <iostream>

using namespace std;

static const int maxN = 50;

int computeP(int n) {
	static int knowns[maxN];
	if (knowns[n] != 0) return knowns[n];
	int t = n;
	if (n < 1) return 0;
	bool isEven = (n % 2 == 0);
	if (n > 1) t = n / 2 + knowns[n / 2] + knowns[isEven ? (n / 2) : (n / 2 + 1)];
	return knowns[n] = t;
}

int main() {
	int n, result;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		result = computeP(i);
	}
	cout << "result: " << result << endl;
}