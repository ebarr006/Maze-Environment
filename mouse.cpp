#include "mouse.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

Mouse::Mouse() {
	iPos = 15;
	jPos = 0;
	direction = 0;
	dist = 0;
}

void Mouse::scan(const Maze &m) {
	switch (direction) {
		case 0:
		std::cout << "Case 0:\n";
		mem.maze[iPos][jPos].l = m.maze[iPos][jPos].l;
		if (jPos != 0) {
			mem.maze[iPos][jPos-1].r = m.maze[iPos][jPos].l;
		}
		
		mem.maze[iPos][jPos].t = m.maze[iPos][jPos].t;
		if (iPos != 0) {
			mem.maze[iPos-1][jPos].d = m.maze[iPos][jPos].t;
		}
		
		mem.maze[iPos][jPos].r = m.maze[iPos][jPos].r;
		if (jPos != 15) {
			mem.maze[iPos][jPos+1].l = m.maze[iPos][jPos].r;
		}
		
		break;
		
		case 1:
		std::cout << "Case 1:\n";
		mem.maze[iPos][jPos].t = m.maze[iPos][jPos].t;
		if (iPos != 0) {
			mem.maze[iPos-1][jPos].d = m.maze[iPos][jPos].t;
		}
		
		mem.maze[iPos][jPos].r = m.maze[iPos][jPos].r;
		if (jPos != 15) {
			mem.maze[iPos][jPos+1].l = m.maze[iPos][jPos].r;
		}
		mem.maze[iPos][jPos].d = m.maze[iPos][jPos].d;
		if (iPos != 15) {
			mem.maze[iPos+1][jPos].t = m.maze[iPos][jPos].d;
		}
		break;

		case 2:
		std::cout << "Case 2:\n";
		mem.maze[iPos][jPos].r = m.maze[iPos][jPos].r;
		if (jPos != 15) {
			mem.maze[iPos][jPos+1].l = m.maze[iPos][jPos].r;
		}
		
		mem.maze[iPos][jPos].d = m.maze[iPos][jPos].d;
		if (iPos != 15) {
			mem.maze[iPos+1][jPos].t = m.maze[iPos][jPos].d;
		}
		
		mem.maze[iPos][jPos].l = m.maze[iPos][jPos].l;
		if (jPos != 0) {
			mem.maze[iPos][jPos-1].r = m.maze[iPos][jPos].l;
		}
		break;

		case 3:
		std::cout << "Case 3:\n";
		mem.maze[iPos][jPos].d = m.maze[iPos][jPos].d;
		if (iPos != 15) {
			mem.maze[iPos+1][jPos].t = m.maze[iPos][jPos].d;
		}

		mem.maze[iPos][jPos].l = m.maze[iPos][jPos].l;
		if (jPos != 0) {
			mem.maze[iPos][jPos-1].r = m.maze[iPos][jPos].l;
		}

		mem.maze[iPos][jPos].t = m.maze[iPos][jPos].t;
		if (iPos != 0) {
			mem.maze[iPos-1][jPos].d = m.maze[iPos][jPos].t;
		}
		break;
	}
	mem.print(iPos, jPos, direction);
}

void Mouse::rotate(int dir) {
	direction = dir;
}

void Mouse::step() {
	if (direction == 0) { iPos--; }
	if (direction == 1) { jPos++; }
	if (direction == 2) { iPos++; }
	if (direction == 3) { jPos--; }
	++dist;
}

void Mouse::leftWallFollow() {
	switch (direction) {
		case 0:
		if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else { // u-turn
			rotate(2);
			step();
		}
		break;
		
		case 1:
		if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else { // u-turn
			rotate(3);
			step();
		}
		break;
		
		case 2:
		if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else { // u-turn
			rotate(0);
			step();
		}
		break;
		
		case 3:
		if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else { // u-turn
			rotate(1);
			step();
		}
		break;
	}
	
	std::cout << "\n----------------------\n";
}


void Mouse::rightWallFollow() {
	switch (direction) {
		case 0:
		if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else { // u-turn
			rotate(2);
			step();
		}
		break;
		
		case 1:
		if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else { // u-turn
			rotate(3);
			step();
		}
		break;
		
		case 2:
		if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else if (!mem.maze[iPos][jPos].r) {
			rotate(1);
			step();
		} else { // u-turn
			rotate(0);
			step();
		}
		break;
		
		case 3:
		if (!mem.maze[iPos][jPos].t) {
			rotate(0);
			step();
		} else if (!mem.maze[iPos][jPos].l) {
			rotate(3);
			step();
		} else if (!mem.maze[iPos][jPos].d) {
			rotate(2);
			step();
		} else { // u-turn
			rotate(1);
			step();
		}
		break;
	}
	
	std::cout << "\n----------------------\n";
}

void Mouse::debug() {
	std::cout << "( " << iPos << " , " << jPos << " ):\n";
	if (mem.maze[iPos][jPos].t) { std::cout << "TOP  : wall\n"; } else { std::cout << "TOP  : open \n";}
	if (mem.maze[iPos][jPos].r) { std::cout << "RIGHT: wall\n"; } else { std::cout << "RIGHT: open \n";}
	if (mem.maze[iPos][jPos].d) { std::cout << "DOWN : wall\n"; } else { std::cout << "DOWN : open \n";}
	if (mem.maze[iPos][jPos].l) { std::cout << "LEFT : wall\n"; } else { std::cout << "LEFT : open \n";}
	std::cout << "Cells Traversed: " << dist << std::endl;
}

bool Mouse::isCenter() {
	return ((iPos == 7 && jPos == 7) || (iPos == 7 && jPos == 8) || (iPos == 8 && jPos == 7) || (iPos == 8 && jPos == 8));
}





