/*
author: Kat Zhang
PROG: Modify the standard array-based stack implementation in Section 4.4 (Program 4.7) to 
disallow duplicates with an ignore-the-new-item policy. 
Use a brute-force approach that involves scanning through the whole stack
*/

#include <iostream>

using namespace std;

template <class Item>
class STACK {
private:
	Item* s;
	int N;
public:
	STACK(int maxN) {
		s = new Item[maxN];
		N = 0;
	}
	bool isNew(Item item) {
		bool result = true;
		for (int i = 0; i <= N; ++i) {
			if (s[i] == item) {
				result = false;
				break;
			}
		}
		return result;
	}
	int empty() {
		return N == 0;
	}
	void push(Item item) {
		if (isNew(item) == 1) {
			s[N++] = item; // Push only if item is new
		}
	}
	Item pop() {
		return s[--N];
	}
};

int main() {
	STACK<int> s(10);
	s.push(2);
	s.push(2);
	s.push(3);
}



