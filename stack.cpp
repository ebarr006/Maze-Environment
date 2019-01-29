#include "stack.h"
#include <iostream>

Stack::Stack() {
	top = -1;
}

void Stack::push(Cell c) {
	if (top == MAX - 1) {
		std::cout << "ERR: STACK FUL" << std::endl;
		return;
	}
	++top;
	opts[top] = c;
}

Cell Stack::pop() {
	if (top == -1) {
		std::cout << "ERR: STACK EMPTY" << std::endl;
		Cell x;
		x.ignore = true;
		// weird error trying to return NULL but return type is not pointer (just Cell)
		// temporary workaround FIX ME
		return x;
	}

	Cell item = opts[top];
	--top;

	return item;
}