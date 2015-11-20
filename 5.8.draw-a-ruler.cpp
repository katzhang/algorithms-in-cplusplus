/*
author: Robert Sedgewick
PROG: Divide and conquer to draw a ruler
*/

#include <iostream>

using namespace std;

void rule(int left, int right, int height) {
	int middle = (left + right) / 2;
	if (height > 0) {
		rule(left, middle, height - 1);
		mark(middle, height);
		rule(middle, right, height - 1);
	}
}