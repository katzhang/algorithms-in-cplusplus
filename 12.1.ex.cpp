/*
author: Kat Zhang
PROG: Write an Item class implementation (similar to Program 12.1) to support having 
the symbol-table implementations process items consisting solely of integer keys.
*/

#include <iostream>

using namespace std;

static int maxKey = 1000;

class Item {
private: 
	int keyval;
	float info;
public:
	Item() {
		keyval = maxKey; // Sentinel key for null items
	}
	int key() {
		return keyval;
	}
	int null() {
		return keyval == maxKey;
	}
	void rand() {
		keyval = 1000*::rand()/RAND_MAX;
		info = 1.0*::rand()/RAND_MAX;
	}
	int scan(istream& is = cin) {
		return (is >> keyval >> info) != 0;
	}
	void show(ostream& os = cout) {
		os << keyval << " " << info << endl;
	}
};
ostream& operator<<(ostream& os, Item& x) {
	x.show(os);
	return os;
}

