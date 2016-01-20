/*
author: Robert Sedgewick
PROG: Sample implementation for item ADT
*/

#include <iostream>

using namespace std;

static int maxKey = 1000;
typedef int Key;

class Item {
private: 
	Key keyval;
	float info;
public:
	Item() {
		keyval = maxKey; // Sentinel key for null items
	}
	Key key() {
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

