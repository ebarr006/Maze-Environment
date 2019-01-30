#include "mouse.h"

using namespace std;


// #define VERT_WALL_CONDITION (arr[i][j].top() && arr[i-1][j].down() && IN_VERT_BOUND)
// #define HORZ_WALL_CONDITION (arr[i][j].left() && arr[i][j-1].right() && IN_HORZ_BOUND)

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


int main() {
	
	Maze m("maze.txt");
	Mouse mini;
	
	while (!mini.isCenter()) {
		mini.scan(m);
		mini.debug();
		mini.logic();
		delay(0.75);
	}
	
	return 0;
}