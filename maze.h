#ifndef MAZE_H
#define MAZE_H

#include "cell.h"

using namespace std;

class Maze {
  private:
    // Cell maze[3][3];
    Cell maze[16][16];
    int xPos;
    int yPos;

  public:
    Maze();
    void displayMaze();
};

#endif
