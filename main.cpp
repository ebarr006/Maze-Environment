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

int main() {
	Maze m("maze3.txt");
	Mouse mini;	
	
	cout << "\n\nSelect a Strategy:\n[1]  Left Wall Follow\n[2]  Right Wall Follow\n[3]  Random Search\n[4]  Flood Fill\n> ";
	char s = cin.get();
	
	if (s == '1') { mini.strat = &Mouse::leftWallFollow; }
	if (s == '2') { mini.strat = &Mouse::rightWallFollow; }
	if (s == '3') { mini.strat = &Mouse::leftRightMix; }
	if (s == '4') { mini.strat = &Mouse::floodFill; }
	
	while (!mini.isCenter()) { // && s != '\n') {
		mini.scan(m);
		mini.debug();
		(mini.*(mini.strat))();
		delay(.10);
		// cin.ignore();
	}
	cout << "\nSolved! <(0 u 0 <)\n" << endl;
	return 0;
}
