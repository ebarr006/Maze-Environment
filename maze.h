#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include <string>
#include <iostream>
#include <fstream>

#define IN_HORZ_BOUND j-1>-1
#define IN_VERT_BOUND i-1>-1
#define SIZE 16


class Maze {
	public:
		bool printNums;
		Cell maze[SIZE][SIZE];
		Maze();
		Maze(std::string filename);
		void print(int i, int j, int dir);
};

#endif