#ifndef STACK_H
#define STACK_H

#include "cell.h"
#define MAX 256 // 16 * 16

class Stack {
	private:
		int top;

	public:
		Cell stack[MAX];
		Stack();
		bool isEmpty();
		bool push(Cell c);
		Cell pop();

};

#endif