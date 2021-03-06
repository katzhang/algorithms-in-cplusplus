/*
author: Robert Sedgewick
PROG: Sample implementation for item data type
*/

#include <iostream>
#include "6.9.sample-interface-for-item-data-type.h"

using namespace std;

int operator<(const Item& A, const Item& B) {
	return A.key < B.key;
}
int scan(Item& x) {
	return (cin >> x.key >> x.info) != 0;
}
void rand(Item& x) {
	x.key = 1000 * (1.0 * rand() / RAND_MAX);
	x.info = 1.0 * rand() / RAND_MAX;
}
void show(const Item& x) {
	cout << x.key << " " << x.info << endl;
}

