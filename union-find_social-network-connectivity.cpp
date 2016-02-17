/*
author: Kat Zhang
PROG: Social network connectivity

Given a social network containing N members and a log file containing M timestamps at which times pairs of members 
formed friendships, design an algorithm to determine the earliest time at which all members are connected 
(i.e., every member is a friend of a friend of a friend ... of a friend). 
Assume that the log file is sorted by timestamp and that friendship is an equivalence relation. 
The running time of your algorithm should be MlogN or better and use extra space proportional to N.

*/

#include <iostream>

using namespace std;

int main() {
	int N, timestamp, person_a, person_b, i, j;

	cout << "what is the total number of people?" << endl;
	cin >> N;

	int id[N], size[N];

	for (i = 0; i < N; i++) {
		id[i] = i;
		size[i] = 1;
	}

	cout << "enter logs: " << endl;

	while (cin >> timestamp >> person_a >> person_b) {
		for (i = person_a; i != id[i]; i = id[i]);
		for (j = person_b; j != id[j]; j = id[j]);

		if (i == j) {
			continue;
		}

		// Weighted quick-union follows at most lgN poiters to determine if 2 are connected

		if (size[i] < size[j]) {
			id[i] = j;
			size[j] += size[i];
		} else {
			id[j] = i;
			size[i] += size[j];
		}

		cout << " person a: " << person_a << " and person b:  " << person_b << " are connected now" << endl;

		if (size[i] == N || size[j] == N) {
			cout << "all people are connected at timestamp: " << timestamp << endl;
		}
	}
}