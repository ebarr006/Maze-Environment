#include "mouse.h"

#define UP '^'
#define DOWN 'v'
#define LEFT '<'
#define RIGHT '>'

Mouse::Mouse() {
	iPos = 15;
	jPos = 0;
	direction = 0;
	// dist = 0;
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
	// mem.print(iPos, jPos, direction);
}

void Mouse::rotate(int dir) {
	direction = dir;
}

void Mouse::step() {
	if (direction == 0) { iPos--; }
	if (direction == 1) { jPos++; }
	if (direction == 2) { iPos++; }
	if (direction == 3) { jPos--; }
	mem.maze[iPos][jPos].found = true;
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

void Mouse::leftRightMix() {
	int mixer = rand() % 2;
	if (mixer) { leftWallFollow(); }
	else { rightWallFollow(); }
}

void Mouse::floodFill() {
	// collect minimum distance of open neighbors
	int minVal = 0;
	
	if (stk.empty()) {
		stk.push(Node(iPos, jPos, mem.maze[iPos][jPos].dist));
	}
	while (!stk.empty()) {
		// std::cout << "stack size: " << stk.size() << std::endl;
		Node temp = stk.top();
		stk.pop();
		// std::cout << "Temp: ( " << temp.i << " , " << temp.j << " )  | Dist: " << temp.dis << std::endl;
		minVal = getMinNeighbor(temp.i, temp.j);
		if (temp.dis != (1 + minVal)) {
			mem.maze[temp.i][temp.j].dist = 1 + minVal;
			if (!mem.maze[temp.i][temp.j].t) {
				Node t( (temp.i-1), temp.j, mem.maze[temp.i-1][temp.j].dist );
				//std::cout << "Pushing TOP..." << std::endl;
				stk.push( t );
			}
			if (!mem.maze[temp.i][temp.j].r) {
				Node t( temp.i, (temp.j+1), mem.maze[temp.i][temp.j+1].dist );
				//std::cout << "Pushing RIGHT..." << std::endl;
				stk.push( t );
			}
			if (!mem.maze[temp.i][temp.j].d) {
				Node t( (temp.i+1), temp.j, mem.maze[temp.i+1][temp.j].dist );
				//std::cout << "Pushing DOWN..." << std::endl;
				stk.push( t );
			}
			if (!mem.maze[temp.i][temp.j].l) {
				Node t( temp.i, (temp.j-1), mem.maze[temp.i][temp.j-1].dist );
				//std::cout << "Pushing LEFT..." << std::endl;
				stk.push( t );
			}
		}
	}
	// std::cout << "--------after flood--------" << std::endl;
	
	
	minVal = getMinNeighbor(iPos, jPos);
	// std::cout << "Curr: ( " << iPos << " , " << jPos << " ) " << direction << std::endl;
	if (!mem.maze[iPos][jPos].t && (mem.maze[iPos-1][jPos].dist == mem.maze[iPos][jPos].dist-1) && !mem.maze[iPos-1][jPos].found) {
		rotate(0);
	}
	else if (!mem.maze[iPos][jPos].r && (mem.maze[iPos][jPos+1].dist == mem.maze[iPos][jPos].dist-1) && !mem.maze[iPos][jPos+1].found) {
		rotate(1);
	}
	else if (!mem.maze[iPos][jPos].d && (mem.maze[iPos+1][jPos].dist == mem.maze[iPos][jPos].dist-1) && !mem.maze[iPos+1][jPos].found) {
		rotate(2);
	}
	else if (!mem.maze[iPos][jPos].l && (mem.maze[iPos][jPos-1].dist == mem.maze[iPos][jPos].dist-1) && !mem.maze[iPos][jPos-1].found) {
		rotate(3);
	}
	// ----
	else if (!mem.maze[iPos][jPos].t && (mem.maze[iPos-1][jPos].dist == mem.maze[iPos][jPos].dist-1)) {
		rotate(0);
	}
	else if (!mem.maze[iPos][jPos].r && (mem.maze[iPos][jPos+1].dist == mem.maze[iPos][jPos].dist-1)) {
		rotate(1);
	}
	else if (!mem.maze[iPos][jPos].d && (mem.maze[iPos+1][jPos].dist == mem.maze[iPos][jPos].dist-1)) {
		rotate(2);
	}
	else if (!mem.maze[iPos][jPos].l && (mem.maze[iPos][jPos-1].dist == mem.maze[iPos][jPos].dist-1)) {
		rotate(3);
	}
	step();
	mem.print(iPos, jPos, direction);
	// std::cout << "outside" << std::endl;
}

int Mouse::getMinNeighbor(int i, int j) {
	int top = 999, down = 999, left = 999, right = 999;
	if (!mem.maze[i][j].t) { top = mem.maze[i-1][j].dist; }
	if (!mem.maze[i][j].r) { right = mem.maze[i][j+1].dist; }
	if (!mem.maze[i][j].d) { down = mem.maze[i+1][j].dist; }
	if (!mem.maze[i][j].l) { left = mem.maze[i][j-1].dist; }
	
	int a;
	int b;
	int minVal;
	
	if (top <= down) {
		a = top;
	} else {
		a = down;
	}
	if (left <= right) {
		b = left;
	} else {
		b = right;
	}
	if (a <= b) {
		minVal = a;
	} else {
		minVal = b;
	}	
	return minVal;
}

int Mouse::getI() {
	return iPos;
}

int Mouse::getJ() {
	return jPos;
}

int Mouse::getD() {
	return direction;
}

void Mouse::debug() {
	std::cout << "( " << iPos << " , " << jPos << " ):\n";
	if (mem.maze[iPos][jPos].t) { std::cout << "TOP  : wall\n"; } else { std::cout << "TOP  : open \n";}
	if (mem.maze[iPos][jPos].r) { std::cout << "RIGHT: wall\n"; } else { std::cout << "RIGHT: open \n";}
	if (mem.maze[iPos][jPos].d) { std::cout << "DOWN : wall\n"; } else { std::cout << "DOWN : open \n";}
	if (mem.maze[iPos][jPos].l) { std::cout << "LEFT : wall\n"; } else { std::cout << "LEFT : open \n";}
}

bool Mouse::isCenter() {
	return ((iPos == 7 && jPos == 7) || (iPos == 7 && jPos == 8) || (iPos == 8 && jPos == 7) || (iPos == 8 && jPos == 8));
}

bool Mouse::isStart() {
	return (iPos == 15 && jPos == 0);

}





