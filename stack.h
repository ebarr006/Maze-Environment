#ifndef STACK_H
#define STACK_H

#include "cell.h"
#define MAX 256

class Stack {
	private:
		Cell opts[MAX];
		int top;

	public:
		Stack();
		void push(Cell c);
		Cell pop();
};

#endif