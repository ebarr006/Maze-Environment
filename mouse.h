#ifndef MOUSE_H
#define MOUSE_H

#include "maze.h"

class Mouse {
	private:
		Maze mem;
		int iPos;
		int jPos;
		int direction;
		int dist;
	
	public:
		Mouse();
		void scan(const Maze &m);
		void rotate(int dir);
		void step();
		void leftWallFollow();
		void debug();
		bool isCenter();
};

#endif