#ifndef MOUSE_H
#define MOUSE_H

#include "maze.h"
#include "Node.h"
#include <cstdlib>
#include <stack>

class Mouse {
	private:
		Maze mem;
		std::stack <Node> stk;
		int iPos;
		int jPos;
		int direction;
		// int dist;
	
	public:
		Mouse();
		void scan(const Maze &m);
		void rotate(int dir);
		void step();
		void (Mouse::*strat)();
		void leftWallFollow();
		void rightWallFollow();
		void leftRightMix();
		void floodFill();
		int getMinNeighbor(int, int, int&);
		int getI();
		int getJ();
		int getD();
		void debug();
		bool isCenter();
		bool isStart();
};

// https://stackoverflow.com/questions/2402579/function-pointer-to-member-function

#endif