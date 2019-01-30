#include "mouse.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

Mouse::Mouse() {
	iPos = 15;
	jPos = 0;
	direction = 0;
}

void Mouse::scan(const Maze &m) {
	switch (direction) {
		case 0:
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
		
		// if (mem.maze[iPos][jPos].l) { std::cout << "LEFT  wall set\n"; }
		// if (mem.maze[iPos][jPos].t) { std::cout << "TOP   wall set\n"; }
		// if (mem.maze[iPos][jPos].r) { std::cout << "RIGHT wall set\n"; }
		
		break;
		
		case 1:
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

void Mouse::move(int dir) {
	if (dir == 0) { iPos--; }
	if (dir == 1) { jPos++; }
	if (dir == 2) { iPos++; }
	if (dir == 3) { jPos--; }
}

void Mouse::logic() {
	bool avail[4] = { !mem.maze[iPos][jPos].t, !mem.maze[iPos][jPos].r, !mem.maze[iPos][jPos].d, !mem.maze[iPos][jPos].l};
	if (avail[0]) {
		std::cout << "top open\n";
	}
	if (avail[1]) {
		std::cout << "right open\n";
	}
	if (avail[2]) {
		std::cout << "down open\n";
	}
	if (avail[3]) {
		std::cout << "left open\n";
	}
	
	if (avail[3]) {
		rotate(0);
		move(0);
	} else if (avail[1]) {
		rotate(1);
		move(1);
	} else if (avail[0]) {
		rotate(2);
		move(2);
	} else if (avail[1]) {
		rotate(3);
		move(3);
	}
}

bool Mouse::isCenter() {
	return ((iPos == 7 && jPos == 7) || (iPos == 7 && jPos == 8) || (iPos == 8 && jPos == 7) || (iPos == 8 && jPos == 8));
}





