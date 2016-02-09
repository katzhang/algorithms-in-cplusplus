/*
author: Robert Sedgewick
PROG: Hash function for string keys
*/

#include <iostream>

using namespace std;

int hashForStringKeys(char* key, int M) {
	int hash = 0, prime_base = 127;
	for (; *key != 0; key++) {
		hash = (prime_base * hash + *key) % M;
		cout << "hash: " << hash << endl;
	}
	return hash;
}

int main() {

	int h = hashForStringKeys("kab", 97);
	cout << "final hash: " << h << endl;
}

