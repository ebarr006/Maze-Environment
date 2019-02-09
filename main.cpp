#include "mouse.h"

using namespace std;

int main(int argc, char** argv) {
	double t = 0.10;
	
	if (argc != 1) {
		for (int i = 0; argv[i] != '\0'; i++) {
			if (strcmp(argv[i], "-h") == 0) {
				cout << "\t-t\t\tPass time amount between steps i.e., 0.50 for half a second,\n";
				cout << "\t\t\t2 for 2 seconds.\n";
				cout << "\t\t\t(Default time value is 0.10 seconds)\n";
				cout << "\t-x\t\tSome new parameter I'll add later.\n";
				cout << "\t-h\t\tDisplay all argument parameters.\n";
				
				return 0;
			}
			if (strcmp(argv[i], "-t") == 0) {
				t = atof(argv[i+1]);
			}
		}
	}
	
	
	Maze m("maze3.txt");
	Mouse mini;
	
	char s;
	bool flag = false;
	
	while (!flag){
		cout << "------------------\n" << "Select a Strategy:\n" << "------------------\n";
		cout << "[1]  Left Wall Follow\n[2]  Right Wall Follow\n[3]  Random Search\n[4]  Flood Fill\n> ";
		s = cin.get();
		if (s == '1') { mini.strat = &Mouse::leftWallFollow; flag = true;}
		if (s == '2') { mini.strat = &Mouse::rightWallFollow; flag = true;}
		if (s == '3') { mini.strat = &Mouse::leftRightMix; flag = true;}
		if (s == '4') { mini.strat = &Mouse::floodFill; flag = true;}
		else { cout << "\nINVALID INPUT\n\n"; }
		s = cin.get();
	}
	
	while (!mini.isCenter()) { // && s != '\n') {
		mini.scan(m);
		mini.debug();
		(mini.*(mini.strat))();
		mini.delay(t);
		// cin.ignore();
	}
	cout << "\nSolved! <(0 u 0 <)\n" << endl;
	return 0;
}
