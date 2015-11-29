/*
author: Robert Sedgewick
PROG: Data-type implementation for string items
*/

#include <iostream>
#include <string>
#include "6.9.sample-interface-for-item-data-type.h"

using namespace std;

static char buf[100000];
static int cnt = 0;

int operator<(const Item& a, const Item& b) {
	return strcmp(a.str, b.str) < 0;
}

void show(const Item& x) {
	cout << x.str << " ";
}

int scan(Item& x) {
	int flag = (cin >> (x.str = &buf[cnt])) != 0;
	cnt += strlen(x.str) + 1;
	return flag;
}

