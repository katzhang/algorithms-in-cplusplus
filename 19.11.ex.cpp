/*
author: Kat Zhang
PROG: Write a program to generate random sparse digraphs for a well-chosen set of values
of V and E.
*/

#include <iostream>
#include "17.9.graph-adt-imp-adj-list.cpp"

using namespace std;

int main() {
	static void randG(Graph& G,  int V, int E) {
		double p = 2.0 * E / G.V() / (G.V() - 1);
		for (int i = 0; i < G.V(); i++) {
			for (int j = 0; j < i; j++) {
				if (rand() < p * RAND_MAX) {
					G.insert(Edge(i, j));
				}
			}
		}
	}
}