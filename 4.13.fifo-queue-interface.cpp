/*
author: Robert Sedgewick
PROG: FIFO queue ADT interface
*/

#include <iostream>

template <class Item>
class QUEUE {
private:
public:
	QUEUE(int);
	int empty();
	void put(Item);
	Item get();
}