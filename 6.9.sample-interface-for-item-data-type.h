/*
author: Robert Sedgewick
PROG: Sample interface for item data type
*/

#include <iostream>

using namespace std;

typedef struct record {
	int key;
	float info;
} Item;

int operator<(const Item&, const Item&);
int scan(Item&);
void rand(Item&);
void show(const Item&);

