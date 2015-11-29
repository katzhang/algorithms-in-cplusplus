/*
author: Robert Sedgewick
PROG: Data-type implementation for record items
*/

#include <iostream>
#include "6.12.data-type-interface-for-record.h"

using namespace std;

static const int maxN = 10000;
static record data[maxN];
static int cnt = 0;

void show(const Item& x) {
	cout << x.r->name << " " << x.r->num << endl;
}

int scan(Item& x) {
	x.r = &data[cnt++];
	return (cin >> x.r->name >> x.r->num) != 0;
}

// Pointer sort on "num" integers
int operator<(const Item& a, const Item& b) {
	return a.r->num < b.r->num;
}

// Pointer sort on "name" strings
int operator<(const Item& a, const Item& b) {
	return strcmp(a.r->name, b.r->name) < 0;
}

