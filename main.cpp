#include "mouse.h"

using namespace std;

void delay(double secondsToDelay)
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

// https://www.learncpp.com/cpp-tutorial/78-function-pointers/

int main() {
	
	Maze m("maze.txt");
	Mouse mini;
	
	while (!mini.isCenter()) {
		mini.scan(m);
		mini.debug();
		mini.leftWallFollow();
		//delay(0.15);
	}
	
	return 0;
}