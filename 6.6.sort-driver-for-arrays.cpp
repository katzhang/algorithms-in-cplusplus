/*
author: Robert Sedgewick
PROG: Sort driver for arrays
*/

#include <iostream>
#include "Item.h"
#include "exch.h"
#include "6.7.interface-for-array-data-type.h"

using namespace std;

int main(int argc, char* argv[]) {
	int N = atoi(argv[1]), sw = atoi(argv[2]);
	Item* a = new Item[N];
	if (sw) {
		rand(a, N);
	} else {
		scan(a, N);
	}
	sort(a, 0, N - 1);
	show(a, 0, N - 1);
}


