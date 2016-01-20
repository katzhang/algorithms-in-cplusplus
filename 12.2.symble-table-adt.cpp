/*
author: Robert Sedgewick
PROG: Symbol-table abstract data type
*/

#include <iostream>

using namespace std;

static int maxKey = 1000;
typedef int Key;

template <class Item, class Key>
class ST {
private:
	// Implementation-dependent code
public:
	ST(int);
	int count();
	Item search(Key) ;
	void insert(Item);
	void remove(Item);
	Item select(int);
	void show(ostream&);
};

