#include "mouse.h"
#include "stack.h"

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
	cout << "\n\nSelect a Strategy:\n[1]  Left Wall Follow\n[2]  Right Wall Follow\n[3]  Flood Fill (under construction)\n\n> ";
	char s = cin.get();
	
	Maze m("maze.txt");
	Mouse mini;	
	
	if (s == '1') { mini.strat = &Mouse::leftWallFollow; }
	if (s == '2') { mini.strat = &Mouse::rightWallFollow; }
	if (s == '3') { cout << "Still under construction! Select another strategy <(O_O<)\n"; }
	// if (s == 3) {mini.strat = &Mouse::FloodFill;}
	
	while (!mini.isCenter()) {
		mini.scan(m);
		mini.debug();
		(mini.*(mini.strat))();
		delay(0.40);
	}
	cout << "Solved!" << endl;
	
	//
	// Stack s;
	// Cell box1(true, true, true, true, 1);
	// Cell box2(false, false, false, false, 2);
	// Cell box3(true, false, false, true, 3);
	//
	// cout << "isEmpty(): " << s.isEmpty() << endl;
	// s.push(box1);
	// cout << "--------------" << endl;
	// s.push(box2);
	// cout << "--------------" << endl;
	// s.push(box3);
	// cout << "--------------" << endl;
	// cout << "isEmpty(): " << s.isEmpty() << endl;
	// cout << "--------------" << endl;
	// Cell x = s.pop();
	// cout << "x Weight: " << x.weight << endl;
	// cout << "--------------" << endl;
	// x = s.pop();
	// cout << "x Weight: " << x.weight << endl;
	// cout << "--------------" << endl;
	// x = s.pop();
	// cout << "x Weight: " << x.weight << endl;
	// cout << "--------------" << endl;
	
	
	return 0;
}
