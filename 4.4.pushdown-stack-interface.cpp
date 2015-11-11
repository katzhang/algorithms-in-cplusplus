/*
author: Robert Sedgewick
PROG: Pushdown-stack ADT interface
*/

template <class Item>
class STACK {
private:
	// implementation-dependent code
public:
	STACK(max_size);
	int empty() const;
	void push(Item item);
	Item pop();
};


