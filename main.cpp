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
