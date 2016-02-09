/*
author: Robert Sedgewick
PROG: Universal hash function (for string keys)
*/

#include <iostream>

using namespace std;

int hashForStringKeys(char* key, int M) {
	int hash = 0;
	int a = 31415, b = 27183;
	for (; *key != 0; key++, a = a * b % (M - 1)) {
		hash = (a * hash + *key) % M;
		cout << "hash: " << hash << endl;
	}
	return (hash < 0) ? (hash + M) : hash;
}

int main() {

	int h = hashForStringKeys("kab", 97);
	cout << "final hash: " << h << endl;
}

