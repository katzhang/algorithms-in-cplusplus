/*
author: Kat Zhang
PROG: Stack with max. 
Create a data structure that efficiently supports the stack operations 
(push and pop) and also a return-the-maximum operation. 
Assume the elements are natural numbers so that you can compare them.
*/

#include <iostream>
using namespace std;

class STACK {
private:
	int* s;
	int N;
	int maxN;
	int* maxes;
public:
	STACK() {
		s = new int[50];
		N = 0;
		maxN = 1;
		maxes = new int[50];
	}
	int empty() {
		return N == 0;
	}
	int size() {
		return N;
	}
	void push(int item) {
		int max = maxes[maxN - 1];
		if (item >= max) {
			maxes[maxN++] = item;
		}
		s[N++] = item;
	}
	int pop() {
		int last = s[--N];
		int max = maxes[maxN - 1];
		if (last == max) {
			maxN--;
			max = maxes[maxN - 1];
		}
		return last;
	}
	int getMax() {
		return maxes[maxN - 1];
	}
};

int main() {
	STACK s;
	s.push(3);
	s.push(34);
	s.push(2);
	s.pop();
	s.pop();
	cout << s.getMax() << endl;

}



