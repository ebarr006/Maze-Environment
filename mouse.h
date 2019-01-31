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
		void (Mouse::*strat)();
		void leftWallFollow();
		void rightWallFollow();
		void debug();
		bool isCenter();
};

// https://stackoverflow.com/questions/2402579/function-pointer-to-member-function

#endif