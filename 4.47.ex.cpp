/*
author: Kat Zhang
PROG: Write a client that tests deque ADTs
*/

#include <iostream>
#include "4.45.ex.cpp"

using namespace std;

int main(int argc, char *argv[]) {
	char* a = argv[1];
	int N = atoi(a);

	DEQUE<int> d(N);
	d.addFirst(3);
	d.addLast(5);
	d.addFirst(4);
	d.removeLast();
	d.removeFirst();
	d.print();
}