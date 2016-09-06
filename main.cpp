#include <iostream>
#include "maze.h"

using namespace std;

void delayProgram(double secondsToDelay)
{
  double startTime = double(clock()); //Start timer
  double secondsPassed;
  bool flag = true;
  while(flag)
  {
    secondsPassed = (double(clock() - startTime)) / double(CLOCKS_PER_SEC);;
    if(secondsPassed >= secondsToDelay)
      {
        flag = false;
      }
    }
}

void randomSearch() {
  Maze m1;
  m1.inputMaze();
  int a = 0;
  while (!m1.isCenter()) {
    m1.displayMaze();
    m1.peripherals();
    a = m1.logic();
    m1.rotate(a);
    m1.displayMaze();
    m1.moveMouse(a);
    delayProgram(0.25);
  }
  m1.printImport();
}

int main() {
  randomSearch();
  
  return 0;
}

// refering to maze.cpp -> moveMouse()
//    - in regards to checking bot wall, MUST make sure that when generating
//      the maze initially, set corresponding adjacent cell's walls after
//      setting a wall. Ex. if i set maze[3][3]'s bottom wall, i must make sure
//      to set maze[4][3]'s top wall. displayMaze() only references top and left
//      walls, so printing ~should~ be unaffected.


// WILL HAVE TO HAVE 2 SEPERATE MAZES, the unknown maze (walls already set)
// and the other being the printed terminal maze. adjust CheckPeripherals
// the if statement should check the invisible maze, the subsequent code should
// set the resulting walls for the displayed maze

// ACCOUNT FOR DEAD-ENDS, WHERE isTop(), isLeft(), isRight() ALL RETURN (1);
// MUST U-TURN;
