#include "mouse.h"

using namespace std;

int main(int argc, char** argv) {
	double t = 0.10;
	string filename = "maze3.txt";
	
	if (argc != 1) {
		for (int i = 0; argv[i] != '\0'; i++) {
			if (strcmp(argv[i], "-h") == 0) {
				cout << "\t-t\t\tPass time amount between steps i.e., 0.50 for half a second,\n";
				cout << "\t\t\t2 for 2 seconds.\n";
				cout << "\t\t\t(Default time value is 0.10 seconds)\n";
				cout << "\t-m\t\tPass in a maze to solve via textfile\n";
				cout << "\t-h\t\tDisplay all argument parameters.\n";
				
				return 0;
			}
			if (strcmp(argv[i], "-t") == 0) {
				t = atof(argv[i+1]);
			}
			if (strcmp(argv[i], "-m") == 0) {
				cout << argv[i+1] << endl;
				filename = argv[i+1];
			}
		}
	}
	
	
	Maze m(filename.c_str());
	Mouse mini;
	
	char s;
	bool flag = false;
	
	while (!flag){
		cout << "------------------\n" << "Select a Strategy:\n" << "------------------\n";
		cout << "[1]  Left Wall Follow\n[2]  Right Wall Follow\n[3]  Random Search\n[4]  Flood Fill\n> ";
		s = cin.get();
		if (s == '1') { mini.strat = &Mouse::leftWallFollow; flag = true; break;}
		if (s == '2') { mini.strat = &Mouse::rightWallFollow; flag = true; break;}
		if (s == '3') { mini.strat = &Mouse::leftRightMix; flag = true; break;}
		if (s == '4') { mini.strat = &Mouse::floodFill; flag = true; break;}
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
	cout << "\nSolved! :) \n" << endl;
	// while (!mini.isStart()) {
	// 	// mini.step();
	// 	mini.scan(m);
	// 	mini.debug();
	// 	mini.returnHome();
	// 	mini.delay(t);
	// }

	return 0;
}
