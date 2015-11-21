/*
author: Kat Zhang
PROG: Modify Program 5.1 to compute N! mod M, such that overflow is no longer an issue. 
Try running your program for M = 997 and N = 10^3, 10^4, 10^5, and 10^6, 
to get an indication of how your programming system handles deeply nested recursive calls
*/

#include <iostream>
#include <math.h>

using namespace std;

long long int getFactorialMod(long long int n, int m) {
	if (n == 0) return 1 % m;
	return (getFactorialMod(n - 1, m) * n) % m;
}

int main() {
	int m = 997;
	long long int n;
	cin >> n;
	cout << getFactorialMod(n, m) << endl;

}