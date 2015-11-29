/*
author: Robert Sedgewick
PROG: Data-type implementation for string items
*/

#include <iostream>

struct record {
	char name[30];
	int num;
};

typedef struct {
	record* r;
} Item;

int operator<(const Item&, const Item&);
void rand(Item&);
void show(const Item&);
int scan(Item&);

