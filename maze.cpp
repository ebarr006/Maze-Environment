#include "maze.h"

using namespace std;

Maze::Maze(string filename) {
	ifstream file;
	file.open(filename.c_str());
	int i = 0; int j = 0; int status = 0;
	
	while ((i != SIZE) && (j != SIZE)) {
		file >> status;
		switch(status) {
			case 0: //00 no walls
			break;
			
			case 1: //01 - left off, top on
			hidden[i][j].t = true;
			if (i != 0) {
				hidden[i-1][j].d = true;
			}
			break;
						
			case 10: // 10 - left on, top off
			hidden[i][j].l = true;
			if (j != 0) {
				hidden[i][j-1].r = true;
			}
			break;
			
			case 11: // 11 - left on, top on
			hidden[i][j].l = true;
			hidden[i][j].t = true;
			if (j != 0 ) {
				hidden[i][j-1].r = true;
			}
			if (i != 0) {
				hidden[i-1][j].d = true;
			}
		}
		++j;
		if (j == 16) {
			j = 0;
			++i;
		}
	}
	printLearned();
}

void Maze::printHidden() {
	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < SIZE; j++) {
				if (k == 0) {
					cout << "+";
					((hidden[i][j].top() && hidden[i-1][j].down() && IN_VERT_BOUND) || i == 0) ? cout << "---" : cout << "   ";
				}
				else if (k == 1) {
					if ((learned[i][j].left() && learned[i][j-1].right() && IN_HORZ_BOUND) || j == 0) {
						cout << "|";
					} else {
						cout << " ";
					}
					if (i == mini.i && j == mini.j) {
						cout << " " << mini.direction << " ";
					} else {
						cout << "   ";
					}
				}
			}
			(k == 0) ? cout << "+" << endl : cout << "|" << endl;
		}
	}
	cout << "+";
	for (int i = 0; i < SIZE; ++i) {
		cout << "---+";
	}
	cout << endl;
}

void Maze::printLearned() {
	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < SIZE; j++) {
				if (k == 0) {
					cout << "+";
					((learned[i][j].top() && learned[i-1][j].down() && IN_VERT_BOUND) || i == 0) ? cout << "---" : cout << "   ";
				}
				else if (k == 1) {
					if ((learned[i][j].left() && learned[i][j-1].right() && IN_HORZ_BOUND) || j == 0) {
						cout << "|";
					} else {
						cout << " ";
					}
					if (i == mini.i && j == mini.j) {
						cout << " " << mini.direction << " ";
					} else {
						cout << "   ";
					}
				}
			}
			(k == 0) ? cout << "+" << endl : cout << "|" << endl;
		}
	}
	cout << "+";
	for (int i = 0; i < SIZE; ++i) {
		cout << "---+";
	}
	cout << endl;
}

void Maze::scan() {
	
}

