/*
author: Kat Zhang
PROG: Write an interface for the deque ADT
*/

#include <iostream>

template <class Item>
class DEQUE {
private:
public:
	DEQUE(int);
	int empty();
	void addFirst(Item item);
	void addLast(Item item);
	Item removeFirst();
	Item removeLast();
}