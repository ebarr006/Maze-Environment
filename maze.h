#ifndef MAZE_H
#define MAZE_H

#include "cell.h"

using namespace std;

class Maze {
  private:
    // Cell maze[3][3];
    Cell pmaze[16][16];
    Cell rmaze[16][16];
    int iPos;
    int jPos;
    int a, b, c;      // palceholders for available options
    int face;

  public:
    Maze();
    void displayMaze();
    void peripherals();
    int logic();
    void moveMouse(int);
    void rotate(int);
};

#endif
