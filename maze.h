#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include "mouse.h"
#include <string>
#include <iostream>
#include <fstream>

#define IN_HORZ_BOUND j-1>-1
#define IN_VERT_BOUND i-1>-1
#define SIZE 16


class Maze {
	private:
		Mouse mini;
		Cell hidden[SIZE][SIZE];
		Cell learned[SIZE][SIZE];

	public:
		Maze(std::string filename);
		void printHidden();
		void printLearned();
		void scan();
		
};

#endif