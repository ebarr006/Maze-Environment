#include "maze.h"

using namespace std;

int numDigits(int x) {
	if (x == 0) return 1;
	int digits = 0;
	// count digits to determine printing width of cell
	while (x != 0) {
		digits++;
		x /= 10;
	}
	return digits;
}

Maze::Maze() {
	for (int i = 0; i < SIZE; ++i) {
		maze[0][i].t = true;
		maze[i][15].r = true;
		maze[15][i].d = true;
		maze[i][0].l = true;
	}
	printNums = true;
	// upper left
	for (int i = 0; i < SIZE/2; ++i) {
		for (int j = 0; j < SIZE/2; ++j) {
			maze[i][j].dist = (SIZE-2) - i - j;
		}
	}
	
	//upper right
	for (int i = 0; i < SIZE/2; ++i) {
		for (int j = (SIZE/2); j < SIZE; ++j) {
			maze[i][j].dist = j - 1 - i;
		}
	}
	
	// lower left
	for (int i = (SIZE/2); i < SIZE; ++i) {
		for (int j = 0; j < (SIZE/2); ++j) {
			maze[i][j].dist = i - 1 - j;
		}
	}
	
	// lower right
	for (int i = 0; i < SIZE/2; ++i) {
		for (int j = 0; j < SIZE/2; ++j) {
			maze[i+(SIZE/2)][j+(SIZE/2)].dist = j+i;
		}
	}
	// maze[SIZE/2 - 1][SIZE/2 - 1].dist = 0;
	// maze[SIZE/2 - 1][SIZE/2].dist = 0;
	// maze[SIZE/2][SIZE/2 - 1].dist = 0;
	// maze[SIZE/2][SIZE/2].dist = 0;
	print(15, 0, 0);
}

Maze::Maze(string filename) {
	printNums = false;
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
	// maybe display only bottom 2 digits if digits >= 3	
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
					} else if (printNums && maze[i][j].found) {
						int x = maze[i][j].dist;
						switch (numDigits(x)) {
							case 1:
							cout << " " << x << " ";
							break;
							
							case 2:
							cout << x << " ";
							break;
							
							case 3:
							cout << x;
						} 
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
