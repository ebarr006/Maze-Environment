#include "maze.h"

using namespace std;

Maze::Maze() {
	for (int i = 0; i < SIZE; ++i) {
		maze[0][i].t = true;
		maze[i][15].r = true;
		maze[15][i].d = true;
		maze[i][0].l = true;
	}
	print(15, 0, 0);
}

Maze::Maze(string filename) {
	cout << "\nImported Maze:\n";
	ifstream file;
	file.open(filename.c_str());
	int i = 0; int j = 0; int status = 0;
	
	for (int i = 0; i < SIZE; ++i) {
		maze[0][i].t = true;
		maze[i][15].r = true;
		maze[15][i].d = true;
		maze[i][0].l = true;
	}
	
	while ((i != SIZE) && (j != SIZE)) {
		file >> status;
		switch(status) {
			case 0: //00 no walls
			break;
			
			case 1: //01 - left off, top on
			maze[i][j].t = true;
			if (i != 0) {
				maze[i-1][j].d = true;
			}
			break;
						
			case 10: // 10 - left on, top off
			maze[i][j].l = true;
			if (j != 0) {
				maze[i][j-1].r = true;
			}
			break;
			
			case 11: // 11 - left on, top on
			maze[i][j].l = true;
			maze[i][j].t = true;
			if (j != 0 ) {
				maze[i][j-1].r = true;
			}
			if (i != 0) {
				maze[i-1][j].d = true;
			}
		}
		++j;
		if (j == 16) {
			j = 0;
			++i;
		}
	}
	print(15, 0, 0);
}

void Maze::print(int iCord, int jCord, int dir) {
	for (int i = 0; i < SIZE; i++) {
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < SIZE; j++) {
				if (k == 0) {
					cout << "+";
					((maze[i][j].t && maze[i-1][j].d && IN_VERT_BOUND) || i == 0) ? cout << "---" : cout << "   ";
				}
				else if (k == 1) {
					if ((maze[i][j].l && maze[i][j-1].r && IN_HORZ_BOUND) || j == 0) {
						cout << "|";
					} else {
						cout << " ";
					}
					if (i == iCord && j == jCord) {
						cout << " ";
						if (dir == 0) { cout << '^'; }
						if (dir == 1) { cout << '>'; }
						if (dir == 2) { cout << 'v'; }
						if (dir == 3) { cout << '<'; }
						cout << " ";
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














