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
	cout << "\n\nSelect a Strategy:\n[1]  Left Wall Follow\n[2]  Right Wall Follow\n[3]  Random Search\n[4]  Flood Fill\n> ";
	char s = cin.get();
	
	Maze m("maze2.txt");
	Mouse mini;	
	
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
	cout << "Solved!" << endl;
	
	while(!mini.isStart()) { // && s != '\n') {
		mini.scan(m);
		mini.debug();
		(mini.*(mini.strat))();
		delay(.15);
		// cin.ignore();
	}
	cout << "Returned!" << endl;
		
	return 0;
}
