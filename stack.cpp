#include "stack.h"
#include <iostream>

Stack::Stack() {
	top = -1;
}

bool Stack::push(Cell c) {
	// std::cout << "top before PUSH: " << top << std::endl;
	if (top >= MAX - 1) {
		std::cout << "ERROR: STACK FULL" << std::endl;
		return false;
	} else {
		++top;
		stack[top] = c;
		// std::cout << "top after PUSH: " << top << std::endl;
		return true;
	}
}

Cell Stack::pop() {
	std::cout << "top before POP: " << top << std::endl;
	if (top < 0) {
		std::cout << "ERROR: STACK EMPTY" << std::endl;
		exit(0);
	} else {
		Cell temp = stack[top];
		--top;
		std::cout << "top after POP: " << top << std::endl;
		return temp;
	}
}

bool Stack::isEmpty() {
	return (top < 0);
}