#ifndef MOUSE_H
#define MOUSE_H

#include "maze.h"

class Mouse {
	private:
		Maze mem;
		int iPos;
		int jPos;
		int direction;
	
	public:
		Mouse();
		void scan(const Maze &m);
		void rotate(int dir);
		void move(int dir);
		void logic();
		void debug();
		bool isCenter();
};

#endif